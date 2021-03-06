cmake_minimum_required(VERSION 3.5)

project(lab6_substr_serch_BENCHMARK)

set(MAIN_BENCHMARK_TEST benchmark_substr_serch.cpp benchmark_substr_serch.h)

FetchContent_MakeAvailable(GoogleBenchmark)

set(FETCHCONTENT_UPDATES_DISCONNECTED ON)

add_executable(${PROJECT_NAME} ${MAIN_BENCHMARK_TEST})

#set(BENCHMARK_FORMAT json)

set_target_properties(
        ${PROJECT_NAME} PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
        BENCHMARK_OUT_FORMAT json
)

target_include_directories(
        ${PROJECT_NAME}
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/../substr_serch
)

target_link_libraries(
        ${PROJECT_NAME}
        benchmark_main
        benchmark
)

if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE
            /W4
            )
else()
    target_compile_options(${PROJECT_NAME} PRIVATE
            -Werror -Wall -Wimplicit-fallthrough -pedantic-errors
            )
endif()


install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION ${CMAKE_HOME_DIRECTORY}/lab_1/benchmark)
install(FILES ${MAIN_BENCHMARK_TEST} DESTINATION ${CMAKE_HOME_DIRECTORY}/lab_1/benchmark )