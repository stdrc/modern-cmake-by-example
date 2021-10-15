#pragma once

#include <string>

#include <wolfram/alpha.hpp>

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

        // 下面是非常 fancy 的两个函数，使用了 C++14 的 auto 返回类型、
        // C++17 的 if constexpr 和 C++20 的 constraints。

        namespace impl {
            template <typename T>
            auto to_string(T &&t) {
                if constexpr (requires { std::to_string(t); }) {
                    return std::to_string(std::forward<T>(t));
                } else if constexpr (requires { std::string(t); }) {
                    return std::string(std::forward<T>(t));
                }
            }
        } // namespace impl

        template <typename T, typename U>
        requires requires(T &&t, U &&u) {
            impl::to_string(std::forward<T>(t));
            impl::to_string(std::forward<U>(u));
        }
        auto check_the_answer(T &&given, U &&expected) {
            return impl::to_string(std::forward<T>(given)) == impl::to_string(std::forward<U>(expected));
        }
    } // namespace v2

    using namespace v2;
} // namespace answer
