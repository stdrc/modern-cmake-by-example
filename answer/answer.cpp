#include "answer/answer.hpp"

#include <wolfram/alpha.hpp>

namespace answer {
    namespace v1 {
        int find_the_ultimate_answer() {
            return 42;
        }
    } // namespace v1

    namespace v2 {
        std::string find_the_ultimate_answer() {
            // 改成了调用 wolfram 库的 API，而不是使用 CURL 发请求
            return wolfram::simple_query("YAPKJY-8XT9VEYPX9", "what is the ultimate answer?");
        }
    } // namespace v2
} // namespace answer
