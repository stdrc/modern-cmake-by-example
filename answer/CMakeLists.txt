set(WOLFRAM_APPID
    ""
    CACHE STRING "WolframAlpha APPID")

if(WOLFRAM_APPID STREQUAL "")
    message(SEND_ERROR "WOLFRAM_APPID must not be empty")
endif()

#[[
INTERFACE 类型的 target 一般用于没有源文件的情况，比如
header-only 库，或者只是为了抽象地提供一组 target_xxx
的配置。

INTERFACE target 的后续所有 target_xxx 都必须也使用
INTERFACE，效果将会直接应用到链接此库的 target 上。

本步骤将 libanswer 从 STATIC target 改成 INTERFACE
target 不会影响 answer_app 中使用它的代码。
#]]
add_library(libanswer INTERFACE)
target_include_directories(libanswer
                           INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_compile_definitions(libanswer INTERFACE WOLFRAM_APPID="${WOLFRAM_APPID}")
target_link_libraries(libanswer INTERFACE wolfram)
