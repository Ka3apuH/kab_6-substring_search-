CMAKE_MINIMUM_REQUIRED(VERSION 3.5)

PROJECT(lab_6_substrSerch VERSION 0.0.1)

include(FetchContent)

FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG        e2239ee6043f73722e7aa812a459f54a28552929 # release-1.10.0
)

ADD_SUBDIRECTORY(test)
ADD_SUBDIRECTORY(benchmark)
