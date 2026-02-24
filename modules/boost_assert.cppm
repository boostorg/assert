module;

#include <boost/config.hpp>
#include <boost/cstdint.hpp>

export module boost.assert;

import std;

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winclude-angled-in-module-purview"
#endif

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 5244)
#endif

#define BOOST_ASSERT_INTERFACE_UNIT
#define BOOST_CONFIG_SKIP_IMPORT_STD
#include <boost/assert/source_location.hpp>
