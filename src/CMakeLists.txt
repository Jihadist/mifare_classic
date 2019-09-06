# CMakeList.txt: проект CMake для block; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.14)

# Добавьте источник в исполняемый файл этого проекта.

set(SOURCE_LIB block.cpp trailer.cpp card.cpp)		

set ( CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

add_library(data SHARED ${SOURCE_LIB})
target_include_directories(data PUBLIC ${PROJECT_SOURCE_DIR}/include)
file(GLOB SRC_FILES ${PROJECT_SOURCE_DIR}/*.cpp)



#set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
#set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# TODO: Добавьте тесты и целевые объекты, если это необходимо.