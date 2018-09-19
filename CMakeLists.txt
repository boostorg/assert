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

        cmake_parse_arguments(_ "" "PREFIX;NAME" "SOURCES;LIBRARIES" ${ARGN})

        if(NOT __PREFIX)
            set(__PREFIX ${PROJECT_NAME})
        endif()

        if(NOT __NAME)
            list(GET __SOURCES 0 __NAME)
            string(MAKE_C_IDENTIFIER ${__NAME} __NAME)
        endif()

        set(__NAME ${__PREFIX}-${__NAME})

        add_executable(${__NAME} EXCLUDE_FROM_ALL ${__SOURCES})
        target_link_libraries(${__NAME} ${__LIBRARIES})

        add_test(NAME compile-${__NAME} COMMAND "${CMAKE_COMMAND}" --build ${CMAKE_BINARY_DIR} --target ${__NAME})

        add_test(NAME run-${__NAME} COMMAND ${__NAME})
        set_tests_properties(run-${__NAME} PROPERTIES DEPENDS compile-${__NAME})

    endfunction(boost_test)

endif()

if(COMMAND boost_test)

    add_subdirectory(test)

endif()
