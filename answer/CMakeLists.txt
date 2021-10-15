add_library(libanswer STATIC answer.cpp)
target_include_directories(libanswer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# libanswer 改成直接使用 wolfram 库提供的 API，无需关心 CURL
target_link_libraries(libanswer PRIVATE wolfram)
