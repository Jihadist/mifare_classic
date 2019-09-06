# CMakeList.txt: файл проекта CMake верхнего уровня; проведите глобальную конфигурацию
# и включите сюда подпроекты.
#
cmake_minimum_required (VERSION 3.14)

project ("mifare")

# Включите подпроекты.
add_subdirectory (src)

set(SOURCE_EXE main.cpp)

add_executable(mifare ${SOURCE_EXE})

set ( CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

target_link_libraries(mifare data)
install(TARGETS mifare 
        EXPORT data
		ARCHIVE
		CONFIGURATIONS Debug
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        RUNTIME DESTINATION bin
        INCLUDES DESTINATION include
        )

install(TARGETS mifare 
        EXPORT data
		CONFIGURATIONS RelMinSize
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        RUNTIME DESTINATION bin
        INCLUDES DESTINATION include
        )

#install(EXPORT data NAMESPACE mp_ DESTINATION ../../../lib/)

#set_target_properties(mifare PROPERTIES
#    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
#    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
#    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
#)