// Copyright 2022 Peter Dimov
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt

#include <boost/assert/source_location.hpp>
#include <boost/core/lightweight_test.hpp>

boost::source_location s_loc = BOOST_CURRENT_LOCATION;

boost::source_location f( boost::source_location const& loc = BOOST_CURRENT_LOCATION )
{
    return loc;
}

int main()
{
    {
        BOOST_TEST_CSTR_EQ( s_loc.file_name(), __FILE__ );
        BOOST_TEST_EQ( s_loc.line(), 8 );
        BOOST_TEST_CSTR_EQ( s_loc.function_name(), "" );
    }

    {
        boost::source_location loc = f();

#if defined(__cpp_lib_source_location) && __cpp_lib_source_location >= 201907L && !BOOST_WORKAROUND(BOOST_MSVC, < 1931)

        BOOST_TEST_CSTR_EQ( loc.file_name(), std::source_location::current().file_name() );
        BOOST_TEST_CSTR_EQ( loc.function_name(), std::source_location::current().function_name() );
        BOOST_TEST_EQ( loc.line(), 24 );

#else

        BOOST_TEST_CSTR_EQ( loc.file_name(), __FILE__ );
        BOOST_TEST_EQ( loc.line(), 10 );
        BOOST_TEST_CSTR_EQ( loc.function_name(), "" );

#endif
    }

    return boost::report_errors();
}
