#include <catch2/catch_test_macros.hpp>

#include <answer/answer.hpp>

using namespace answer;

// 使用 Catch2 编写测试用例

TEST_CASE("Can compare string and string", "[check_the_answer]") {
    REQUIRE(check_the_answer("Hello", "Hello") == true);
    REQUIRE(check_the_answer("Hello", "world") == false);
    REQUIRE(check_the_answer("13", std::string("13")) == true);
}

TEST_CASE("Can compare string and integer", "[check_the_answer]") {
    REQUIRE(check_the_answer("13", 13) == true);
    REQUIRE(check_the_answer("13", 14) == false);
    REQUIRE(check_the_answer(13, "13") == true);
    REQUIRE(check_the_answer(13, std::string("13")) == true);
    REQUIRE(check_the_answer(13, std::string("14")) == false);
}
