cmake_minimum_required(VERSION 3.0.0)

project(OLAS VERSION 1.0)
add_executable(${PROJECT_NAME} main.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_BINARY_DIR})

#Adder Use logic
option(USE_ADDER "A simple library for adding two floats." ON)

if(USE_ADDER)
    add_subdirectory(Adder)
    list (APPEND EXTRA_LIB_DIRS Adder)
    list (APPEND EXTRA_INCLUDE_DIRS Adder)
    list (APPEND EXTRA_LINKS adder)
endif()

configure_file(OLASConfig.h.in OLASConfig.h)

add_subdirectory(external/glfw)

target_include_directories(${PROJECT_NAME} 
    PUBLIC external/glfw/include
    ${EXTRA_INCLUDE_DIRS}
)

target_link_directories(${PROJECT_NAME} 
    PRIVATE external/glfw/src
    ${EXTRA_LIB_DIRS}
)   


target_link_libraries(${PROJECT_NAME} 
    glfw
    ${EXTRA_LINKS}
      
)

