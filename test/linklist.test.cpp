#include <algorithm>
#include <catch2/catch.hpp>

// TEST_CASE("Test link_list operation", "[link_list]")
// {
//     link_list<int> list(20);

//     SECTION("construct")
//     {
//         REQUIRE(list.size() == 20);
//         REQUIRE(std::all_of(list.begin(), list.end(), [](int i) { return i == int(); }));

//         link_list<int> list2(10, 10);
//         REQUIRE(list2.size() == 10);
//         REQUIRE(std::all_of(list2.begin(), list2.end(), [](int i) { return i == 10; }));

//         link_list<int> list3(list2);
//         REQUIRE(list3.size() == 10);
//         REQUIRE(std::all_of(list3.begin(), list3.end(), [](int i) { return i == 10; }));

//         link_list<int> list4(std::move(list3));
//         REQUIRE(list4.size() == 10);
//         REQUIRE(std::all_of(list4.begin(), list4.end(), [](int i) { return i == 10; }));
//         REQUIRE(list3.size() == 0);

//         // link_list<int> list5(list.begin(), list.end());
//         // REQUIRE(list5.size() == 20);
//         // REQUIRE(std::all_of(list5.begin(), list5.end(), [](int i) { return i == int(); }));

//         // link_list<int> list6({1, 2, 3, 4, 5});
//         // REQUIRE(list6.size() == 5);
//         // REQUIRE(std::all_of(list6.begin(), list6.end(), [](int i) { return i > 0 && i < 6; }));
//     }

//     SECTION("append")
//     {
//         list.push_back(10);
//         REQUIRE(list.size() == 21);
//         REQUIRE(list.back() == 10);
        
//         link_list<int> list2(10, 10);
//         list.push_back(list2);
//         REQUIRE(list.size() == 31);
//         REQUIRE(list.back() == 10);

//         // list.push_back(list2.begin(), list2.end());
//         // REQUIRE(list.size() == 41);
//         // REQUIRE(list.back() == 10);

//         // list.push_back({1, 2, 3, 4, 5});
//         // REQUIRE(list.size() == 46);
//         // REQUIRE(list.back() == 5);
//     }

//     SECTION("back_erase")
//     {
//         list.back_erase(list.begin());
//         REQUIRE(list.size() == 19);

//         // remove (0, 10) | 1-9
//         list.back_erase(list.begin(), list.begin().advance(10));
//         REQUIRE(list.size() == 10);

//         list.back_erase(list.before_begin(), list.end());
//         REQUIRE(list.size() == 0);
//     }

//     SECTION("clear")
//     {
//         list.clear();
//         REQUIRE(list.size() == 0);

//         list.clear();
//         REQUIRE(list.size() == 0);
//     }

//     SECTION("assign")
//     {
//         link_list<int> list2(10);
//         list = list2;
//         REQUIRE(list.size() == 10);
//         REQUIRE(list2.size() == 10);
//         list = std::move(list2);
//         REQUIRE(list.size() == 10);
//         REQUIRE(list2.size() == 0);
//     }

//     SECTION("resize")
//     {
//         list.resize(30);
//         REQUIRE(list.size() == 30);
//         list.resize(5);
//         REQUIRE(list.size() == 5);
//         list.resize(30);
//         REQUIRE(list.size() == 30);
//         list.resize(0);
//         REQUIRE(list.size() == 0);
//         list.resize(5);
//         REQUIRE(list.size() == 5);
//     }

//     SECTION("change data")
//     {
//         list.front() = 10;
//         REQUIRE(list.front() == 10);
//         list.back() = 20;
//         REQUIRE(list.back() == 20);

//         *std::find(list.begin(), list.end(), 10) = 30;
//         REQUIRE(list.front() == 30);
//         *std::find(list.begin(), list.end(), 20) = 40;
//         REQUIRE(list.back() == 40);
//     }
// }