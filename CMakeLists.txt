cmake_minimum_required(VERSION 3.9)
project(answer)

# 添加 answer 子目录
add_subdirectory(answer)

add_executable(answer_app main.cpp)
target_link_libraries(answer_app libanswer)

#[[
使用如下命令构建本项目：

    cmake -B build      # 生成构建目录
    cmake --build build # 执行构建
    ./build/answer_app  # 运行 answer_app 程序
#]]
