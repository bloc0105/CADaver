cmake_minimum_required(VERSION 2.8...3.20)
project(Solution)

add_subdirectory(Executable)
add_subdirectory(Library)

#https://thatonegamedev.com/cpp/cmake/godot-4-gdextension-for-c-using-cmake/
add_subdirectory(libs)
add_subdirectory(LibraryGD)

set_property(DIRECTORY PROPERTY VS_STARTUP_PROJECT Executable)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set(PREDEFINED_TARGETS_FOLDER "CustomTargets")

set_property(DIRECTORY PROPERTY VS_STARTUP_PROJECT Library)