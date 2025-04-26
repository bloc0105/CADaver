cmake_minimum_required(VERSION 2.8...3.20)
project(Solution)

#IF(CMAKE_BUILD_TYPE MATCHES DEBUG)
#    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
#ENDIF(CMAKE_BUILD_TYPE MATCHES DEBUG)


include(FetchContent)

#https://thatonegamedev.com/cpp/cmake/godot-4-gdextension-for-c-using-cmake/
FetchContent_Declare(
        GDExtension
        GIT_REPOSITORY https://github.com/godotengine/godot-cpp.git
        GIT_TAG godot-4.3-stable
)

FetchContent_MakeAvailable(GDExtension)

add_subdirectory(Executable)
add_subdirectory(Library)


set_property(DIRECTORY PROPERTY VS_STARTUP_PROJECT Executable)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set(PREDEFINED_TARGETS_FOLDER "CustomTargets")

set_property(DIRECTORY PROPERTY VS_STARTUP_PROJECT Library)