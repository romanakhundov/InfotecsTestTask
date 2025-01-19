cmake_minimum_required(VERSION 3.30.2)

project(program_2)
include_directories(src)

set(HEADERS
	server.h)
	
set(SOURCES
	src/server.cpp
	src/main.cpp)
	
add_executable(program_2 ${SOURCES} ${HEADERS})
