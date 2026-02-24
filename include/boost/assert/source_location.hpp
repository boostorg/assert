#ifndef BOOST_ASSERT_SOURCE_LOCATION_HPP_INCLUDED
#define BOOST_ASSERT_SOURCE_LOCATION_HPP_INCLUDED

// http://www.boost.org/libs/assert
//
// Copyright 2019, 2021 Peter Dimov
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt

#if defined(BOOST_USE_MODULES) && !defined(BOOST_ASSERT_INTERFACE_UNIT)

#ifndef BOOST_ASSERT_SKIP_IMPORT
import boost.assert;
#endif

#else

#ifndef BOOST_USE_MODULES
#include <boost/config.hpp>
#include <boost/cstdint.hpp>
#endif
#include <boost/config/std/string.hpp>
#include <boost/config/std/cstdio.hpp>
#include <boost/config/std/cstring.hpp>

#if !defined(BOOST_NO_IOSTREAM)
#include <boost/config/std/iosfwd.hpp>
#endif

#if defined(__cpp_lib_source_location) && __cpp_lib_source_location >= 201907L
# include <boost/config/std/source_location.hpp>
#endif

// BOOST_ASSERT_MODULE_EXPORT
#ifdef BOOST_USE_MODULES
#  define BOOST_ASSERT_MODULE_EXPORT export
#else
#  define BOOST_ASSERT_MODULE_EXPORT
#endif

namespace boost
{

BOOST_ASSERT_MODULE_EXPORT struct source_location
{
private:

    char const * file_;
    char const * function_;
    boost::uint_least32_t line_;
    boost::uint_least32_t column_;

public:

    BOOST_CONSTEXPR source_location() BOOST_NOEXCEPT: file_( "" ), function_( "" ), line_( 0 ), column_( 0 )
    {
    }

    BOOST_CONSTEXPR source_location( char const * file, boost::uint_least32_t ln, char const * function, boost::uint_least32_t col = 0 ) BOOST_NOEXCEPT: file_( file ), function_( function ), line_( ln ), column_( col )
    {
    }

#if defined(__cpp_lib_source_location) && __cpp_lib_source_location >= 201907L

    BOOST_CONSTEXPR source_location( std::source_location const& loc ) BOOST_NOEXCEPT: file_( loc.file_name() ), function_( loc.function_name() ), line_( loc.line() ), column_( loc.column() )
    {
    }

#endif

    BOOST_CONSTEXPR char const * file_name() const BOOST_NOEXCEPT
    {
        return file_;
    }

    BOOST_CONSTEXPR char const * function_name() const BOOST_NOEXCEPT
    {
        return function_;
    }

    BOOST_CONSTEXPR boost::uint_least32_t line() const BOOST_NOEXCEPT
    {
        return line_;
    }

    BOOST_CONSTEXPR boost::uint_least32_t column() const BOOST_NOEXCEPT
    {
        return column_;
    }

#if defined(BOOST_MSVC)
# pragma warning( push )
# pragma warning( disable: 4996 )
#endif

#if ( defined(_MSC_VER) && _MSC_VER < 1900 ) || ( defined(__MINGW32__) && !defined(__MINGW64_VERSION_MAJOR) )
# define BOOST_ASSERT_SNPRINTF(buffer, format, arg) std::sprintf(buffer, format, arg)
#else
# define BOOST_ASSERT_SNPRINTF(buffer, format, arg) std::snprintf(buffer, sizeof(buffer)/sizeof(buffer[0]), format, arg)
#endif

    std::string to_string() const
    {
        unsigned long ln = line();

        if( ln == 0 )
        {
            return "(unknown source location)";
        }

        std::string r = file_name();

        char buffer[ 16 ];

        BOOST_ASSERT_SNPRINTF( buffer, ":%lu", ln );
        r += buffer;

        unsigned long co = column();

        if( co )
        {
            BOOST_ASSERT_SNPRINTF( buffer, ":%lu", co );
            r += buffer;
        }

        char const* fn = function_name();

        if( *fn != 0 )
        {
            r += " in function '";
            r += fn;
            r += '\'';
        }

        return r;
    }

#undef BOOST_ASSERT_SNPRINTF

#if defined(BOOST_MSVC)
# pragma warning( pop )
#endif

    inline friend bool operator==( source_location const& s1, source_location const& s2 ) BOOST_NOEXCEPT
    {
        return std::strcmp( s1.file_, s2.file_ ) == 0 && std::strcmp( s1.function_, s2.function_ ) == 0 && s1.line_ == s2.line_ && s1.column_ == s2.column_;
    }

    inline friend bool operator!=( source_location const& s1, source_location const& s2 ) BOOST_NOEXCEPT
    {
        return !( s1 == s2 );
    }
};

#if !defined(BOOST_NO_IOSTREAM)

BOOST_ASSERT_MODULE_EXPORT
template<class E, class T> std::basic_ostream<E, T> & operator<<( std::basic_ostream<E, T> & os, source_location const & loc )
{
    os << loc.to_string();
    return os;
}

#endif

} // namespace boost

#endif // Modules compatibility header

// Not safe to include in the interface unit because of includes, and not needed
#if !defined(BOOST_ASSERT_INTERFACE_UNIT)
#include <boost/assert/current_location.hpp>
#endif

#endif // #ifndef BOOST_ASSERT_SOURCE_LOCATION_HPP_INCLUDED
