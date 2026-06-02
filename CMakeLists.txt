cmake_minimum_required(VERSION 3.16)

project(Scriptureware VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(scriptureware
    Source/main.cpp
    Source/ui.cpp
    Source/verse.cpp
)

target_include_directories(scriptureware PRIVATE
    Source
)

install(TARGETS scriptureware
        RUNTIME DESTINATION bin)

install(DIRECTORY Texts/
        DESTINATION share/scriptureware/texts)

target_compile_definitions(scriptureware PRIVATE
    SCRIPTUREWARE_DATA_DIR="/app/share/scriptureware/texts/"
)