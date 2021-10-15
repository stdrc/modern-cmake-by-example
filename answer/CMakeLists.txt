#[[
find_package 用于在系统中寻找已经安装的第三方库的头文件和库文件
的位置，并创建一个名为 CURL::libcurl 的库目标，以供链接。
#]]
find_package(CURL REQUIRED)

add_library(libanswer STATIC answer.cpp)

target_include_directories(libanswer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

#[[
为 libanswer 库链接 libcurl，这里 PRIVATE 和 PUBLIC 的区别是：
CURL::libcurl 库只会被 libanswer 看到，根级别的 main.cpp 中
无法 include curl 的头文件。
#]]
target_link_libraries(libanswer PRIVATE CURL::libcurl)
