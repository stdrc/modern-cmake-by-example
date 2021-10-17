cmake_minimum_required(VERSION 3.14)
project(answer)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    include(CTest)
endif()

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(answer)

add_subdirectory(curl_wrapper)
add_subdirectory(wolfram)

add_executable(answer_app main.cpp)
target_link_libraries(answer_app libanswer)

#[[
使用如下命令构建本项目：

    cmake -B build -DWOLFRAM_APPID=YAPKJY-8XT9VEYPX9 # 生成构建目录（建议更换 WOLFRAM_APPID）
    cmake --build build                              # 执行构建
    ctest --test-dir build -R "^answer."             # 运行 libanswer 测试
    ./build/answer_app                               # 运行 answer_app 程序
#]]
