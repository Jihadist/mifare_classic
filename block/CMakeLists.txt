# CMakeList.txt: проект CMake для block; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

# Добавьте источник в исполняемый файл этого проекта.
#add_executable (mifare "main.cpp" "block.h")

set(SOURCE_EXE main.cpp)
set(SOURCE_LIB "block.cpp")
add_library(block STATIC ${SOURCE_LIB})
set(SOURCE_LIB "trailer.cpp")
add_library(trailer STATIC ${SOURCE_LIB})
add_executable(mifare ${SOURCE_EXE})
target_link_libraries(mifare block trailer)	
# TODO: Добавьте тесты и целевые объекты, если это необходимо.
