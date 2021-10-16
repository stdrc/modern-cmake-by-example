# 导入 FetchContent 相关命令
include(FetchContent)

# 描述如何获取 Catch2
FetchContent_Declare(
    catch2 # 建议使用全小写
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.0.0-preview3)

# 一条龙地下载、构建 Catch2
FetchContent_MakeAvailable(catch2)

#[[
FetchContent 要求 CMake 3.11 或更高版本，在此之间
可以使用 Git submodule + add_subdirectory 的方式
使用没有安装在系统中的第三方库。即使支持 FetchContent
也可以选择使用 Git submodule，各有优劣。

FetchContent_MakeAvailable 要求 CMake 3.14，如果
要支持更旧版本，或者需要更细粒度的控制，可以使用如下替代：

    FetchContent_GetProperties(catch2)
    if(NOT catch2_POPULATED)
        FetchContent_Populate(catch2)
        add_subdirectory(${catch2_SOURCE_DIR} ${catch2_BINARY_DIR})
    endif()
#]]

# macro（宏）类似于 C/C++ 中的宏
macro(answer_add_test TEST_NAME)
    add_executable(${TEST_NAME} ${ARGN}) # ${ARGN} 类似于 C/C++ 中的 __VA_ARGS__
    #[[
    add_test 添加 CTest 可以识别到的测试程序，建议使用项目名前缀，
    方便在运行测试时和别的第三方库的测试区分。
    #]]
    add_test(NAME answer.${TEST_NAME} COMMAND ${TEST_NAME})
    target_link_libraries(${TEST_NAME} PRIVATE libanswer)
    #[[
    链接 Catch2::Catch2WithMain 以使用 Catch2 提供的宏，链接
    Catch2WithMain 时，测试程序中不需要手动编写 main 函数。
    #]]
    target_link_libraries(${TEST_NAME} PRIVATE Catch2::Catch2WithMain)
endmacro()

# 调用上面的 macro 添加测试程序
answer_add_test(test_check_the_answer test_check_the_answer.cpp)
