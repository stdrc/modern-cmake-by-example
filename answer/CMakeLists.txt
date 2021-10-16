set(WOLFRAM_APPID
    ""
    CACHE STRING "WolframAlpha APPID")

if(WOLFRAM_APPID STREQUAL "")
    message(SEND_ERROR "WOLFRAM_APPID must not be empty")
endif()

add_library(libanswer INTERFACE)
target_include_directories(libanswer
                           INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_compile_definitions(libanswer INTERFACE WOLFRAM_APPID="${WOLFRAM_APPID}")
target_compile_features(libanswer INTERFACE cxx_std_20)
target_link_libraries(libanswer INTERFACE wolfram)

# 只在启用了 BUILD_TESTING 的情况下构建测试程序
if(BUILD_TESTING)
    add_subdirectory(tests)
endif()
