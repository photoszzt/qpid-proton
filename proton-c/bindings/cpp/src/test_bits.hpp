#ifndef TEST_BITS_HPP
#define TEST_BITS_HPP
/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

#include <stdexcept>
#include <iostream>
#include <sstream>
#include "msg.hpp"

namespace {

struct fail : public std::logic_error { fail(const std::string& what) : logic_error(what) {} };
#define FAIL(WHAT) throw fail(MSG(__FILE__ << ":" << __LINE__ << ": " << WHAT))
#define ASSERT(TEST) do { if (!(TEST)) FAIL("assert failed: " << #TEST); } while(false)
#define ASSERT_EQUAL(WANT, GOT) if (!((WANT) == (GOT))) \
        FAIL(#WANT << " !=  " << #GOT << ": " << WANT << " != " << GOT)

#define RUN_TEST(BAD_COUNT, TEST)                                       \
    do {                                                                \
        try {                                                           \
            TEST;                                                       \
            break;                                                      \
        } catch(const fail& e) {                                        \
            std::cout << "FAIL " << #TEST << std::endl << e.what() << std::endl; \
        } catch(const std::exception& e) {                              \
            std::cout << "ERROR " << #TEST << std::endl << __FILE__ << ":" << __LINE__ << ": " << e.what() << std::endl; \
        }                                                               \
            ++BAD_COUNT;                                                \
    } while(0)

template<class T> std::string str(const T& x) { std::ostringstream s; s << x; return s.str(); }

}
#endif // TEST_BITS_HPP
