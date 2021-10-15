#include <iostream>

#include <answer/answer.hpp>

/**
 * 由于 libanswer 链接 libcurl 时使用的是 PRIVATE，
 * 在这里我们无法 #include <curl/curl.hpp>。
 *
 * 也就是说使用 PRIVATE 声明的依赖，只在构建 libanswer
 * 时可见，不会溢出并影响 libanswer 的使用者。
 */

int main(int argc, const char *argv[]) {
    for (;;) {
        std::cout << "What is the ultimate answer?" << std::endl;
        std::string answer;
        std::cin >> answer;
        auto expected_answer = answer::find_the_ultimate_answer();
        if (answer == expected_answer) {
            std::cout << "Correct!" << std::endl;
            break;
        }
    }
    return 0;
}
