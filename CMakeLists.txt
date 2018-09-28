# Copyright 2018 Mike Dev
# Copyright 2018 Peter Dimov
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt

cmake_minimum_required(VERSION 3.5)

project(BoostAssert LANGUAGES CXX)

add_library(boost_assert INTERFACE)
add_library(Boost::assert ALIAS boost_assert)

target_include_directories(boost_assert INTERFACE include)

target_link_libraries(boost_assert
    INTERFACE
        Boost::config
)

if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)

    # requires CMake 3.11 so we just carry it around
    include(cmake/FetchContent.cmake)

    message("-- Populating boost_config")
    FetchContent_Populate(boost_config QUIET GIT_REPOSITORY https://github.com/boostorg/config GIT_TAG develop)
    add_subdirectory(${boost_config_SOURCE_DIR} ${boost_config_BINARY_DIR})

    message("-- Populating boost_core")
    FetchContent_Populate(boost_core QUIET GIT_REPOSITORY https://github.com/boostorg/core GIT_TAG develop)
    add_subdirectory(${boost_core_SOURCE_DIR} ${boost_core_BINARY_DIR})

    message("-- Populating mincmake")
    FetchContent_Populate(mincmake QUIET GIT_REPOSITORY https://github.com/pdimov/mincmake GIT_TAG master)
    include(${mincmake_SOURCE_DIR}/cmake/boost_test.cmake)

    enable_testing()

    add_custom_target(check COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure -C $<CONFIG>)

endif()

if(COMMAND boost_test)

    add_subdirectory(test)

endif()
