cmake_minimum_required(VERSION 3.5)

project(lab6_TEST)

set(MAIN_TEST lab_6_test.cpp lab_6_test.h)

FetchContent_MakeAvailable(googletest)

add_executable(${PROJECT_NAME} ${MAIN_TEST})

set_target_properties(
        ${PROJECT_NAME} PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
)

target_include_directories(
        ${PROJECT_NAME}
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/../substr_serch
)

target_link_libraries(
        ${PROJECT_NAME}
        gtest_main
)

include(GoogleTest)

gtest_discover_tests(${PROJECT_NAME}
        XML_OUTPUT_DIR lab_6/Unit_test)

if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE
            /W4
            )
else()
    target_compile_options(${PROJECT_NAME} PRIVATE
            -Werror -Wall -Wimplicit-fallthrough -pedantic-errors
            )
endif()

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION ${CMAKE_HOME_DIRECTORY}/lab_1/Unit_test)
install(FILES ${MAIN_TEST} DESTINATION ${CMAKE_HOME_DIRECTORY}/lab_1/Unit_test )

#set(CPACK_GENERATOR "DEB")
#include(CPack)