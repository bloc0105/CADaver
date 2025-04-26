cmake_minimum_required(VERSION 2.8...3.20)
project(Executable)

############################################################################
############################################################################
############################################################################

find_package(nlohmann_json REQUIRED)
find_package(glm REQUIRED)

find_package(OpenCASCADE)
include_directories(SYSTEM ${OpenCASCADE_INCLUDE_DIR})

############################################################################
############################################################################
############################################################################

set(Source_Files
    "Source/main.cpp"
)
source_group("Source" FILES ${Source_Files})

set(ALL_FILES
    ${Source_Files}
)

############################################################################
############################################################################
############################################################################

add_executable(Executable ${ALL_FILES})
set_property(TARGET Executable PROPERTY CXX_STANDARD 20)


target_link_libraries(Executable
glm::glm
nlohmann_json::nlohmann_json
Library
)

#https://www.youtube.com/watch?v=SfRFG_Pk9pk
#https://dev.opencascade.org/content/buildcompile-application
foreach(LIB ${OpenCASCADE_LIBRARIES})
target_link_libraries(Executable ${OpenCASCADE_LIBRARY_DIR}/${LIB}.lib)
target_link_libraries(Executable debug ${OpenCASCADE_LIBRARY_DIR}/${LIB}.lib)
target_link_libraries(Executable optimized ${OpenCASCADE_LIBRARY_DIR}/${LIB}.lib)
endforeach()

target_include_directories(Executable PUBLIC 
./Source/
)

set_property(DIRECTORY PROPERTY VS_STARTUP_PROJECT Executable)