add_library(wolfram STATIC alpha.cpp)
target_include_directories(wolfram PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# wolfram PRIVATE 地依赖 curl_wrapper
target_link_libraries(wolfram PRIVATE curl_wrapper)
