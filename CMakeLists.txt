
cmake_minimum_required(VERSION 3.25)

project(erbsland-qt-toml-example)

# Detect and load either Qt5 or Qt6.
if (DEFINED Qt6_DIR AND NOT Qt6_DIR MATCHES "-NOTFOUND")
    find_package(Qt6 REQUIRED GLOBAL COMPONENTS Core)
elseif (DEFINED Qt5_DIR AND NOT Qt5_DIR MATCHES "-NOTFOUND")
    find_package(Qt5 REQUIRED GLOBAL COMPONENTS Core)
else()
    find_package(Qt6 GLOBAL COMPONENTS Core)
    if (NOT DEFINED Qt6_FOUND)
        find_package(Qt5 GLOBAL REQUIRED COMPONENTS Core)
    endif ()
endif ()

add_subdirectory(erbsland-qt-toml)
add_subdirectory(example-app)

