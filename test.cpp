#include "list.h"

#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_session.cpp>

TEST_CASE("2LinkedList basic testing", "[List1]")
{
	List list1;

	SECTION("Method `Empty`")
	{
		INFO("Method `Empty` doesn't work properly");
		CHECK(list1.Empty() == true);

		list1.PushFront(419);
		INFO("Method `Empty` doesn't work properly");
		CHECK(list1.Empty() == false);
	}

	SECTION("Method `Size`")
	{
		INFO("Method `Size` doesn't work properly");
		CHECK(list1.Size() == 0);

		for (int i = 0; i < 5; ++i) {
			list1.PushBack((i + 1) * 3);
		}

		INFO("Method `Size` doesn't work properly");
		CHECK(list1.Size() == 5);
	}

	list1.Clear();
	INFO("Method `Clear` doesn't work properly");
	CHECK(list1.Empty() == true);
}

TEST_CASE("2LinkedList Push/Pop testing", "[List2]") 
{
	List list2;

	SECTION("Methods `Push`")
	{
		list2.PushBack(1729);
		list2.PushFront(1000);		
		list2.PushFront(1001);

		INFO("Method `PushBack` doesn't work properly");
		CHECK(list2.PopBack() == 1729);

		INFO("Method `PushFront` doesn't work properly");
		CHECK(list2.PopFront() == 1001);
	}

	SECTION("Methods `Pop`")
	{
		list2.Clear();

		INFO("Method `PopBack` doesn't work properly");
		REQUIRE_THROWS(list2.PopBack());

		INFO("Method `PopFront` doesn't work properly");
		REQUIRE_THROWS(list2.PopFront());

		list2.PushBack(1729);
		list2.PushFront(1000);
		list2.PushFront(1001);

		INFO("Method `PopBack` doesn't work properly");
		CHECK(list2.PopBack() == 1729);

		INFO("Method `PopFront` doesn't work properly");
		CHECK(list2.PopFront() == 1001);
	}
}

int main(int argc, char** argv) 
{
	return Catch::Session().run();
}