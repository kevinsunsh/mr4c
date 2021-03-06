/**
  * Copyright 2014 Google Inc. All rights reserved.
  * 
  * Licensed under the Apache License, Version 2.0 (the "License");
  * you may not use this file except in compliance with the License.
  * You may obtain a copy of the License at
  * 
  *     http://www.apache.org/licenses/LICENSE-2.0
  * 
  * Unless required by applicable law or agreed to in writing, software
  * distributed under the License is distributed on an "AS IS" BASIS,
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
*/


#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include "util/util_api.h"
#include <vector>
#include <set>
#include <stdexcept>

namespace MR4C {

class TestArrayUtil : public CPPUNIT_NS::TestFixture {

	CPPUNIT_TEST_SUITE(TestArrayUtil);
	CPPUNIT_TEST(testVectorToString);
	CPPUNIT_TEST(testSetToString);
	CPPUNIT_TEST(testEmptyContainerToString);
	CPPUNIT_TEST_SUITE_END();

	private:

	public:

		void setUp() {
		}

		void tearDown() {
		}

		void testVectorToString() {
			std::vector<std::string> v;
			v.push_back("one");
			v.push_back("two");
			v.push_back("three");
			std::string expected("one, two, three");
			std::string result = vectorToString<std::string>(v, ",");
			CPPUNIT_ASSERT(expected==result);
		}
		
		void testSetToString() {
			std::set<std::string> v;
			v.insert("one");
			v.insert("two");
			v.insert("three");
			std::string expected("one, three, two");
			std::string result = setToString<std::string>(v, ",");
			CPPUNIT_ASSERT(expected==result);
		}

		void testEmptyContainerToString() {
			std::set<std::string> v;
			std::string expected("");
			std::string result = setToString<std::string>(v, ",");
			CPPUNIT_ASSERT(expected==result);
		}
		
};

CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(TestArrayUtil, "TestArrayUtil");

}
