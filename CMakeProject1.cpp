#pragma once
#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_session.hpp>
#include <List.cpp>

TEST_CASE("Empty function on a freshly created list returns true", "[list]") {
    List list;
    REQUIRE(list.Empty() == true);
}

TEST_CASE("Size function returns correct number of elements in the list", "[list]") {
    List list;
    REQUIRE(list.Size() == 0);

    SECTION("Adding elements to the list updates the size") {
        list.PushFront(42);
        list.PushBack(17);
        REQUIRE(list.Size() == 2);
    }

    SECTION("Removing elements from the list updates the size") {
        list.PushFront(42);
        list.PushBack(17);
        list.PopFront();
        REQUIRE(list.Size() == 1);
        list.PopBack();
        REQUIRE(list.Size() == 0);
    }
}
int main(int argc, char* argv[])
{
    return Catch::Session().run(argc, argv);
}
