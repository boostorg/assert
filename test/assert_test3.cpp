// Copyright 2026 Peter Dimov
// Distributed under the Boost Software License, Version 1.0.
// https://www.boost.org/LICENSE_1_0.txt

// Test for BOOST_ASSERT with both BOOST_DISABLE_ASSERTS and
// BOOST_ENABLE_ASSERT_HANDLER/BOOST_ENABLE_ASSERT_DEBUG_HANDLER

#include <boost/core/lightweight_test.hpp>

#define BOOST_DISABLE_ASSERTS

// BOOST_ENABLE_ASSERT_HANDLER

#define BOOST_ENABLE_ASSERT_HANDLER
#include <boost/assert.hpp>

void test_disabled_handler()
{
    BOOST_ASSERT( 1 );
    BOOST_ASSERT_MSG( 1, "1" );

    BOOST_ASSERT( 0 );
    BOOST_ASSERT_MSG( 0, "0" );
}

#undef BOOST_ENABLE_ASSERT_HANDLER

// BOOST_ENABLE_ASSERT_DEBUG_HANDLER

#define BOOST_ENABLE_ASSERT_DEBUG_HANDLER
#include <boost/assert.hpp>

void test_disabled_debug_handler()
{
    BOOST_ASSERT( 1 );
    BOOST_ASSERT_MSG( 1, "1" );

    BOOST_ASSERT( 0 );
    BOOST_ASSERT_MSG( 0, "0" );
}

// BOOST_ENABLE_ASSERT_DEBUG_HANDLER, BOOST_ENABLE_ASSERT_HANDLER

#define BOOST_ENABLE_ASSERT_HANDLER
#include <boost/assert.hpp>

void test_disabled_both()
{
    BOOST_ASSERT( 1 );
    BOOST_ASSERT_MSG( 1, "1" );

    BOOST_ASSERT( 0 );
    BOOST_ASSERT_MSG( 0, "0" );
}

int main()
{
    test_disabled_handler();
    test_disabled_debug_handler();
    test_disabled_both();

    return boost::report_errors();
}
