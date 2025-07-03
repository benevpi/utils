cmake_minimum_required(VERSION 3.10)
project(mymodule)

find_package(PythonInterp 3.5 REQUIRED)

# This goes after, since it uses PythonInterp as hint
find_package(PythonLibs 3.5 REQUIRED)

include_directories ("${PYTHON_INCLUDE_DIRS}")

add_library(mymodule SHARED mymodule.c)

target_include_directories(mymodule PRIVATE ../include)
target_link_libraries(mymodule pio)

set_target_properties(
    mymodule
    PROPERTIES
        PREFIX ""
        OUTPUT_NAME "mymodule"
        LINKER_LANGUAGE C
    )

