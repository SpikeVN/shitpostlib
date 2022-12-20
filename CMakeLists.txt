cmake_minimum_required(VERSION 3.0)

project(shitpostlib LANGUAGES C)

add_executable(shitpostlib main.c)

install(TARGETS shitpostlib RUNTIME DESTINATION bin)
