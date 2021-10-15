#pragma once

#include <string>

namespace answer {
    namespace v1 {
        int find_the_ultimate_answer();
    } // namespace v1

    namespace v2 {
        std::string find_the_ultimate_answer();
    } // namespace v2

    using namespace v2;
} // namespace answer
