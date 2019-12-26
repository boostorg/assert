# Copyright 2018, 2019 Peter Dimov
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt

# Partial and experimental CMake support
# Subject to change; please do not rely on the contents of this file yet

cmake_minimum_required(VERSION 3.5...3.16)

project(boost_assert VERSION "${BOOST_SUPERPROJECT_VERSION}" LANGUAGES CXX)

add_library(boost_assert INTERFACE)
add_library(Boost::assert ALIAS boost_assert)

target_include_directories(boost_assert INTERFACE include)

target_link_libraries(boost_assert
    INTERFACE
        Boost::config
)

include(BoostInstall OPTIONAL RESULT_VARIABLE HAVE_BOOST_INSTALL)

if(HAVE_BOOST_INSTALL)

    boost_install(TARGETS boost_assert HEADER_DIRECTORY include/)

endif()

if(BUILD_TESTING)

    add_subdirectory(test)

endif()
