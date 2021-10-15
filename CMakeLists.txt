cmake_minimum_required(VERSION 3.9)
project(answer)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(answer)

#[[
拆分了 CURL 和 WolframAlpha 相关代码到单独的子目录中，
其中分别创建了两个库目标：curl_wrapper 和 wolfram，
可以在本项目的其它地方 link。
#]]
add_subdirectory(curl_wrapper)
add_subdirectory(wolfram)

add_executable(answer_app main.cpp)
target_link_libraries(answer_app libanswer)

#[[
使用如下命令构建本项目：

    cmake -B build      # 生成构建目录
    cmake --build build # 执行构建
    ./build/answer_app  # 运行 answer_app 程序
#]]
