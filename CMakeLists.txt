# Copyright 2018-2025 Peter Dimov
# Distributed under the Boost Software License, Version 1.0.
# https://www.boost.org/LICENSE_1_0.txt

# We support CMake 3.5, but prefer 3.20 policies and behavior
cmake_minimum_required(VERSION 3.5...3.20)

project(boost_assert VERSION "${BOOST_SUPERPROJECT_VERSION}" LANGUAGES CXX)

add_library(boost_assert INTERFACE)
add_library(Boost::assert ALIAS boost_assert)

target_include_directories(boost_assert INTERFACE include)

target_link_libraries(boost_assert
  INTERFACE
    Boost::config
)

# Add headers and .natvis to project, for better IDE integration

if(CMAKE_VERSION VERSION_GREATER 3.18 AND CMAKE_GENERATOR MATCHES "Visual Studio")

  # Using target_sources with PRIVATE or PUBLIC on INTERFACE targets requires 3.19

  file(GLOB_RECURSE boost_assert_HEADERS CONFIGURE_DEPENDS include/*.hpp)
  source_group(TREE ${PROJECT_SOURCE_DIR}/include FILES ${boost_assert_HEADERS} PREFIX "Header Files")
  target_sources(boost_assert PRIVATE ${boost_assert_HEADERS})
  unset(boost_assert_HEADERS)

  target_sources(boost_assert PUBLIC extra/boost_assert.natvis)

endif()

# BUILD_TESTING is the standard CTest variable that enables testing

if(BUILD_TESTING)

  add_subdirectory(test)

endif()
