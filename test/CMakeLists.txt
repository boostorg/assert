# Copyright 2018 Peter Dimov
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt

boost_test_jamfile(FILE Jamfile.v2 LIBRARIES Boost::assert Boost::core)

# This one doesn't import
boost_test(TYPE run SOURCES current_function_test.cpp LIBRARIES Boost::assert Boost::core)
