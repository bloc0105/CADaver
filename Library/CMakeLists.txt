cmake_minimum_required(VERSION 2.8...3.20)

find_package(Catch2 REQUIRED)

project(Library)
project(LibraryTest)

find_package(glm REQUIRED)
find_package(nlohmann_json REQUIRED)
find_package(OpenCASCADE)
include_directories(SYSTEM ${OpenCASCADE_INCLUDE_DIR})


set(Source_Files
    "Source/Library/testMain.cpp"
    "Source/Library/HelloWorld.cpp"
    "Source/Library/HelloWorld.h"
)
source_group("Source" FILES ${Source_Files})


set(ALL_FILES
    ${Source_Files}
)

############################################################################
############################################################################
############################################################################

add_executable(LibraryTest ${ALL_FILES})
add_library(Library ${ALL_FILES})
set_property(TARGET LibraryTest PROPERTY CXX_STANDARD 20)
set_property(TARGET Library PROPERTY CXX_STANDARD 20)

target_link_libraries(LibraryTest PUBLIC 
Catch2::Catch2
glm::glm
nlohmann_json::nlohmann_json
)
target_link_libraries(Library PUBLIC 
glm::glm
nlohmann_json::nlohmann_json
)

target_include_directories(Library PUBLIC 
./Source/
)
target_include_directories(LibraryTest PUBLIC 
./Source/
)

#https://www.youtube.com/watch?v=SfRFG_Pk9pk
#https://dev.opencascade.org/content/buildcompile-application
foreach(LIB ${OpenCASCADE_LIBRARIES})
target_link_libraries(Library PRIVATE ${OpenCASCADE_LIBRARY_DIR}/${LIB}.lib)
target_link_libraries(Library PRIVATE debug ${OpenCASCADE_LIBRARY_DIR}/${LIB}.lib)
target_link_libraries(Library PRIVATE optimized ${OpenCASCADE_LIBRARY_DIR}/${LIB}.lib)
target_link_libraries(LibraryTest PRIVATE ${OpenCASCADE_LIBRARY_DIR}/${LIB}.lib)
target_link_libraries(LibraryTest PRIVATE debug ${OpenCASCADE_LIBRARY_DIR}/${LIB}.lib)
target_link_libraries(LibraryTest PRIVATE optimized ${OpenCASCADE_LIBRARY_DIR}/${LIB}.lib)
endforeach()

set_property( TARGET LibraryTest PROPERTY COMPILE_DEFINITIONS ISTESTPROJECT=1 )


include(CTest)
include(Catch)
catch_discover_tests(LibraryTest)