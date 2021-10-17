include(FetchContent)

FetchContent_Declare(
    catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.0.0-preview3)

FetchContent_MakeAvailable(catch2)

macro(answer_add_test TEST_NAME)
    add_executable(${TEST_NAME} ${ARGN})
    add_test(NAME answer.${TEST_NAME} COMMAND ${TEST_NAME})
    target_link_libraries(${TEST_NAME} PRIVATE libanswer)
    target_link_libraries(${TEST_NAME} PRIVATE Catch2::Catch2WithMain)
endmacro()

answer_add_test(test_check_the_answer test_check_the_answer.cpp)
