#[[
创建一个可配置的变量，可以由上级 CMakeLists 或 cmake 命令指定变量值。

这里由于 APPID 是一个应该藏好、不应该放在代码里的值，所以建议在 cmake
命令中通过 -D 参数传入。
#]]
set(WOLFRAM_APPID
    ""
    CACHE STRING "WolframAlpha APPID")

if(WOLFRAM_APPID STREQUAL "")
    message(SEND_ERROR "WOLFRAM_APPID must not be empty")
endif()

add_library(libanswer STATIC answer.cpp)
target_include_directories(libanswer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

#[[
将 WOLFRAM_APPID 添加到编译 .cpp 文件时的 definition 列表，从而
可在 C++ 代码中使用。
#]]
target_compile_definitions(libanswer PRIVATE WOLFRAM_APPID="${WOLFRAM_APPID}")

target_link_libraries(libanswer PRIVATE wolfram)
