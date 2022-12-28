cmake_minimum_required(VERSION 3.0)

project(shitpostlib LANGUAGES C)

add_executable(shitpostlib
	${CMAKE_SOURCE_DIR}/src/main.c
	${CMAKE_SOURCE_DIR}/include/cjson/cJSON.c
	${CMAKE_SOURCE_DIR}/include/utfutils/utf8_decode.c
	${CMAKE_SOURCE_DIR}/include/utfutils/utf8.c
	${CMAKE_SOURCE_DIR}/include/gaylib/gaylib.c
)

target_include_directories(shitpostlib PRIVATE
	${CMAKE_SOURCE_DIR}/src
	${CMAKE_SOURCE_DIR}/include
	${CMAKE_SOURCE_DIR}/include/cjson
	${CMAKE_SOURCE_DIR}/include/utfutils
	${CMAKE_SOURCE_DIR}/include/gaylib
)
