cmake_minimum_required(VERSION 3.5)
project(BoostAssert LANGUAGES CXX)

add_library(boost_assert INTERFACE)
add_library(Boost::assert ALIAS boost_assert)

target_include_directories(boost_assert INTERFACE include)

target_link_libraries(boost_assert
	INTERFACE
		Boost::config
)
