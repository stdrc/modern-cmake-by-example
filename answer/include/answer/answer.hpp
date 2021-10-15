#pragma once

#include <string>

#include <wolfram/alpha.hpp>

// header-only 库的所有实现代码均在头文件中

namespace answer {
    namespace v1 {
        int find_the_ultimate_answer() {
            return 42;
        }
    } // namespace v1

    namespace v2 {
        std::string find_the_ultimate_answer() {
            return wolfram::simple_query(WOLFRAM_APPID, "what is the ultimate answer?");
        }
    } // namespace v2

    using namespace v2;
} // namespace answer
