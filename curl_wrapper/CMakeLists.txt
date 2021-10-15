find_package(CURL REQUIRED)

add_library(curl_wrapper STATIC curl_wrapper.cpp)
target_include_directories(curl_wrapper
                           PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# curl_wrapper PRIVATE 地依赖 CURL::libcurl
target_link_libraries(curl_wrapper PRIVATE CURL::libcurl)
