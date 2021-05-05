cmake_minimum_required(VERSION 3.0.0)

project(OLAS VERSION 0.1.0)


include(CTest)

enable_testing()


add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(Adder)
add_subdirectory(external/glfw)

target_include_directories(${PROJECT_NAME} 
    PUBLIC Adder
    PUBLIc external/glfw/include
)

target_link_directories(${PROJECT_NAME} 
    PRIVATE Adder
    PRIVATE external/glfw/src
)


target_link_libraries(${PROJECT_NAME} 
    adder
    glfw
)

