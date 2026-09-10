// Copyright 2026 Peter Dimov
// Distributed under the Boost Software License, Version 1.0.
// https://www.boost.org/LICENSE_1_0.txt

#define BOOST_ASSERT_HANDLER_IS_NORETURN
#include <boost/assert.hpp>

int main()
{
    BOOST_ASSERT( true );
}
