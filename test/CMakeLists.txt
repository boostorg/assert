# Copyright 2018 Peter Dimov
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt

boost_test(SOURCES assert_test.cpp LIBRARIES Boost::assert Boost::core)
boost_test(SOURCES current_function_test.cpp LIBRARIES Boost::assert Boost::core)
boost_test(SOURCES verify_test.cpp LIBRARIES Boost::assert Boost::core)
boost_test(SOURCES assert_is_void_test.cpp LIBRARIES Boost::assert Boost::core)

# expansion tests are in exp/ so that there is a backslash in the path on Windows

boost_test(SOURCES exp/assert_exp_test.cpp LIBRARIES Boost::assert Boost::core)
boost_test(SOURCES exp/assert_msg_exp_test.cpp LIBRARIES Boost::assert Boost::core)
boost_test(SOURCES exp/verify_exp_test.cpp LIBRARIES Boost::assert Boost::core)
boost_test(SOURCES exp/verify_msg_exp_test.cpp LIBRARIES Boost::assert Boost::core)

boost_test(SOURCES assert_test2.cpp LIBRARIES Boost::assert Boost::core)
boost_test(SOURCES assert_msg_test2.cpp LIBRARIES Boost::assert Boost::core)

boost_test(SOURCES quick.cpp LIBRARIES Boost::assert Boost::core)
