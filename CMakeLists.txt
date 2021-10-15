cmake_minimum_required(VERSION 3.9)
project(answer)

# 添加 libanswer 库目标，STATIC 指定为静态库
add_library(libanswer STATIC answer.cpp)

add_executable(answer main.cpp)

# 为 answer 可执行目标链接 libanswer
target_link_libraries(answer libanswer)

#[[
使用如下命令构建本项目：

    cmake -B build      # 生成构建目录
    cmake --build build # 执行构建
    ./build/answer      # 运行 answer 程序
#]]
