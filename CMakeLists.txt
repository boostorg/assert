# Copyright 2018 Peter Dimov
#
# Distributed under the Boost Software License, Version 1.0.
#
# See accompanying file LICENSE_1_0.txt or copy at
# http://www.boost.org/LICENSE_1_0.txt

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

    add_subdirectory(../config bin/config)
    add_subdirectory(../core bin/core)

    enable_testing()

    add_custom_target(check COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure -C ${CMAKE_CFG_INTDIR})

    function(boost_test)

        cmake_parse_arguments(PARSE "" "NAME" "SOURCES;LIBRARIES" ${ARGN})

        add_executable(${PARSE_NAME} EXCLUDE_FROM_ALL ${PARSE_SOURCES})
        target_link_libraries(${PARSE_NAME} ${PARSE_LIBRARIES})

        add_test(NAME compile-${PARSE_NAME} COMMAND "${CMAKE_COMMAND}" --build ${CMAKE_BINARY_DIR} --target ${PARSE_NAME})

        add_test(NAME run-${PARSE_NAME} COMMAND ${PARSE_NAME})
        set_tests_properties(run-${PARSE_NAME} PROPERTIES DEPENDS compile-${PARSE_NAME})

    endfunction(boost_test)

    add_subdirectory(test)

endif()
