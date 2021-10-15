add_library(libanswer STATIC answer.cpp)

#[[
message 可用于打印调试信息或错误信息，除了 STATUS
外还有 DEBUG WARNING SEND_ERROR FATAL_ERROR 等。
#]]
message(STATUS "Current source dir: ${CMAKE_CURRENT_SOURCE_DIR}")

#[[
给 libanswer 库目标添加 include 目录，PUBLIC 使
这个 include 目录能被外部使用者看到。

当链接 libanswer 库时，这里指定的 include 目录会被
自动添加到使用此库的 target 的 include 路径中。
#]]
target_include_directories(libanswer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
