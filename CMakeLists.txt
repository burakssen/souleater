cmake_minimum_required(VERSION 3.27)
project(souleater)

set(CMAKE_CXX_STANDARD 23)

set(SOURCE_DIR src)
set(VENDOR_DIR vendor)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# compile raylib as a shared library
#set(BUILD_SHARED_LIBS ON)

#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
#set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")

add_subdirectory("${VENDOR_DIR}/raylib")
add_subdirectory("${VENDOR_DIR}/yaml-cpp")

#set(BUILD_SHARED_LIBS OFF)

file(GLOB_RECURSE SOURCE_FILES 
    "${SOURCE_DIR}/**.cpp" 
    "${SOURCE_DIR}/**.h" 
)

set(INCLUDE_DIRECTORIES
    "${SOURCE_DIR}"
    "${VENDOR_DIR}/raylib/src"
    "${VENDOR_DIR}/yaml-cpp/include"
)


add_executable(souleater ${SOURCE_FILES})

target_include_directories(souleater PUBLIC ${INCLUDE_DIRECTORIES})

target_link_libraries(souleater PUBLIC raylib yaml-cpp)

file(COPY "resources" DESTINATION "${CMAKE_BINARY_DIR}")
