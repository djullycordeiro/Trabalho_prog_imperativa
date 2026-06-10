cmake_minimum_required(VERSION 3.31)
project(ProjetoPI-FOP C)

set(CMAKE_C_STANDARD 11)

add_executable(${PROJECT_NAME} 
src/main.c
src/front.c
src/front.h 
src/back.c 
src/back.h
)

# Isso é pra encontrar o gtk em cada sistema operacional
if(APPLE)
    list(APPEND CMAKE_PREFIX_PATH "/opt/homebrew" "/usr/local")
endif()

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK REQUIRED IMPORTED_TARGET gtk4)
target_link_libraries(${PROJECT_NAME} PRIVATE PkgConfig::GTK)
