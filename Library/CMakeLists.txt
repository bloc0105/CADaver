cmake_minimum_required(VERSION 2.8...3.20)

find_package(Catch2 REQUIRED)

project(Library)
#project(LibraryTest)

find_package(glm REQUIRED)
find_package(nlohmann_json REQUIRED)
find_package(nfd CONFIG REQUIRED) 
find_package(OpenCASCADE)
include_directories(SYSTEM ${OpenCASCADE_INCLUDE_DIR})


set(Source_Files
    "Source/Library/testMain.cpp"
)
source_group("Source" FILES ${Source_Files})

set(CADShapes_Files
    "Source/Library/CADShape/CADShape.cpp"
    "Source/Library/CADShape/CADShape.h"
    "Source/Library/CADShape/CADCompound.cpp"
    "Source/Library/CADShape/CADCompound.h"
    "Source/Library/CADShape/CADCompSolid.cpp"
    "Source/Library/CADShape/CADCompSolid.h"
    "Source/Library/CADShape/CADEdge.cpp"
    "Source/Library/CADShape/CADEdge.h"
    "Source/Library/CADShape/CADFace.cpp"
    "Source/Library/CADShape/CADFace.h"
    "Source/Library/CADShape/CADShell.cpp"
    "Source/Library/CADShape/CADShell.h"
    "Source/Library/CADShape/CADSolid.cpp"
    "Source/Library/CADShape/CADSolid.h"
    "Source/Library/CADShape/CADVertex.cpp"
    "Source/Library/CADShape/CADVertex.h"
    "Source/Library/CADShape/CADWire.cpp"
    "Source/Library/CADShape/CADWire.h"
    "Source/Library/CADShape/TopAbs2String.cpp"
    "Source/Library/CADShape/TopAbs2String.h"
    "Source/Library/CADShape/CADShapeFactory.cpp"
    "Source/Library/CADShape/CADShapeFactory.h"
)
source_group("Source/CADShape" FILES ${CADShapes_Files})

set(Util_Files
    "Source/Library/Util/STLWriter.cpp"
    "Source/Library/Util/STLWriter.h"
    "Source/Library/Util/SaveFileDialog.cpp"
    "Source/Library/Util/SaveFileDialog.h"
    "Source/Library/Util/LoadFileDialog.cpp"
    "Source/Library/Util/LoadFileDialog.h"
    "Source/Library/Util/Triangulation.cpp"
    "Source/Library/Util/Triangulation.h"
)
source_group("Source/Util" FILES ${Util_Files})

set(Operation_Files
    "Source/Library/Operation/ExtrudeOperation.cpp"
    "Source/Library/Operation/ExtrudeOperation.h"
    "Source/Library/Operation/TriangulateOperation.cpp"
    "Source/Library/Operation/TriangulateOperation.h"
)
source_group("Source/Operation" FILES ${Operation_Files})

set(ALL_FILES
    ${Source_Files}
    ${Util_Files}
    ${Operation_Files}
    ${CADShapes_Files}
)

############################################################################
############################################################################
############################################################################

#add_executable(LibraryTest ${ALL_FILES})
add_library(Library ${ALL_FILES})
#set_property(TARGET LibraryTest PROPERTY CXX_STANDARD 20)
set_property(TARGET Library PROPERTY CXX_STANDARD 20)

#target_link_libraries(LibraryTest PUBLIC 
#Catch2::Catch2
#glm::glm
#nlohmann_json::nlohmann_json
#nfd::nfd
#)
target_link_libraries(Library PUBLIC 
glm::glm
nlohmann_json::nlohmann_json
nfd::nfd
)

target_include_directories(Library PUBLIC 
./Source/
)
target_include_directories(Library PRIVATE 
./Source/Library/
)
#target_include_directories(LibraryTest PUBLIC 
#./Source/
#)
#target_include_directories(LibraryTest PRIVATE 
#./Source/Library/
#)

#https://www.youtube.com/watch?v=SfRFG_Pk9pk
#https://dev.opencascade.org/content/buildcompile-application
foreach(LIB ${OpenCASCADE_LIBRARIES})
target_link_libraries(Library PRIVATE ${OpenCASCADE_LIBRARY_DIR}/${LIB}.lib)
target_link_libraries(Library PRIVATE debug ${OpenCASCADE_LIBRARY_DIR}/${LIB}.lib)
target_link_libraries(Library PRIVATE optimized ${OpenCASCADE_LIBRARY_DIR}/${LIB}.lib)
#target_link_libraries(LibraryTest PRIVATE ${OpenCASCADE_LIBRARY_DIR}/${LIB}.lib)
#target_link_libraries(LibraryTest PRIVATE debug ${OpenCASCADE_LIBRARY_DIR}/${LIB}.lib)
#target_link_libraries(LibraryTest PRIVATE optimized ${OpenCASCADE_LIBRARY_DIR}/${LIB}.lib)
endforeach()

#set_property( TARGET LibraryTest PROPERTY COMPILE_DEFINITIONS ISTESTPROJECT=1 )


#include(CTest)
#include(Catch)
#catch_discover_tests(LibraryTest)