# Copyright 2018-2025 Peter Dimov
# Distributed under the Boost Software License, Version 1.0.
# https://www.boost.org/LICENSE_1_0.txt

# We support CMake 3.8, but prefer 3.31 policies and behavior
cmake_minimum_required(VERSION 3.8...3.31)

project(boost_assert VERSION "${BOOST_SUPERPROJECT_VERSION}" LANGUAGES CXX)

add_library(boost_assert INTERFACE)
add_library(Boost::assert ALIAS boost_assert)

target_include_directories(boost_assert INTERFACE include)

target_link_libraries(boost_assert
  INTERFACE
    Boost::config
)

# Add headers and .natvis to project, for better IDE integration

file(GLOB_RECURSE boost_assert_HDRFILES CONFIGURE_DEPENDS include/*.hpp)
source_group(TREE ${PROJECT_SOURCE_DIR}/include FILES ${boost_assert_HDRFILES} PREFIX "Header Files")
target_sources(boost_assert PRIVATE ${boost_assert_HDRFILES})
unset(boost_assert_HDRFILES)

target_sources(boost_assert PUBLIC extra/boost_assert.natvis)

# BUILD_TESTING is the standard CTest variable that enables testing

if(BUILD_TESTING)

  add_subdirectory(test)

endif()
