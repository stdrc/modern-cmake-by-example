#include <iostream>

/**
 * target_link_libraries 使得可以像使用系统和第三方库一样
 * 使用子目录中提供的公开头文件。
 */
#include <answer/answer.hpp>

int main(int argc, const char *argv[]) {
    int expected_answer = answer::find_the_ultimate_answer();
    for (;;) {
        std::cout << "What is the ultimate answer?" << std::endl;
        int answer;
        std::cin >> answer;
        if (answer == expected_answer) {
            std::cout << "Correct!" << std::endl;
            break;
        }
    }
    return 0;
}
