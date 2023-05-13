cmake_minimum_required(VERSION 3.25)

project(example-app)

add_executable(example-app src/main.cpp)

target_link_libraries(example-app PRIVATE erbsland-qt-toml)
set_property(TARGET example-app PROPERTY CXX_STANDARD 17)
target_compile_features(example-app PRIVATE cxx_std_17)
add_custom_command(TARGET example-app POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        "${CMAKE_CURRENT_LIST_DIR}/data/config.toml"
        "$<TARGET_FILE_DIR:example-app>/config.toml")

