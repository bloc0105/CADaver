cmake_minimum_required(VERSION 3.19)
project(LibraryGD)

set(Source_Files
    "Source/register_types.h"
    "Source/register_types.cpp"
    "Source/CADShape.h"
    "Source/CADShape.cpp"
)
source_group("Source" FILES ${Source_Files})

set(ALL_FILES
    ${Source_Files}
)

add_library(LibraryGD SHARED ${ALL_FILES})
set_property(TARGET LibraryGD PROPERTY DBG_POSTFIX d)
set_property(TARGET LibraryGD PROPERTY CXX_STANDARD 20)


target_include_directories(LibraryGD PRIVATE 
"${CMAKE_CURRENT_SOURCE_DIR}/src"
./../Library/Source
)

target_link_libraries(LibraryGD PUBLIC 
godot::cpp 
Library)

add_custom_command(TARGET LibraryGD POST_BUILD 
               COMMAND ${CMAKE_COMMAND} -E copy_directory 
               $<TARGET_FILE_DIR:LibraryGD>              
                ${CMAKE_SOURCE_DIR}/godotProject/bin)