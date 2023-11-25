cmake_minimum_required(VERSION 3.10)

project(CopilotPlayground VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)

enable_testing()

include(FetchContent)
##############################################################################################################
# Google test download
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
##############################################################################################################

##############################################################################################################
#  nlohmann's json download
FetchContent_Declare(
  nlohmann_json
  GIT_REPOSITORY https://github.com/nlohmann/json.git
  GIT_TAG v3.10.4
)

FetchContent_MakeAvailable(nlohmann_json)

##############################################################################################################

set(SOURCES
    src/hello.cpp
)
    
set(HEADERS
    inc/hello.hpp
)

set(TESTS
    tests/hello.ut.cpp
)

set(FLAGS -Wall -Wextra -pedantic -Wconversion -Werror)


add_library(${PROJECT_NAME}-lib STATIC ${SOURCES} ${HEADERS})

add_executable(${PROJECT_NAME} src/main.cpp)
add_executable(${PROJECT_NAME}-ut ${TESTS})

target_link_libraries(${PROJECT_NAME} 
PRIVATE 
    ${PROJECT_NAME}-lib
    nlohmann_json::nlohmann_json
)

target_link_libraries(${PROJECT_NAME}-ut ${PROJECT_NAME}-lib gtest_main)

target_include_directories(${PROJECT_NAME} PRIVATE inc)
target_include_directories(${PROJECT_NAME}-ut PRIVATE inc)
target_include_directories(${PROJECT_NAME}-lib PRIVATE inc)

target_compile_options(${PROJECT_NAME} PRIVATE ${FLAGS})
target_compile_options(${PROJECT_NAME}-ut PRIVATE ${FLAGS})
target_compile_options(${PROJECT_NAME}-lib PRIVATE ${FLAGS})

add_test(NAME ${PROJECT_NAME}-tests COMMAND ${PROJECT_NAME}-ut)