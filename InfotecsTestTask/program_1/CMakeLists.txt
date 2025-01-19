cmake_minimum_required(VERSION 3.30.2)

project(program_1)
include_directories(src)

set(HEADERS
	buffer.h
	client.h
	data_processing.h
	data_receiver.h)
set(SOURCES
	src/client.cpp
	src/data_processing.cpp
	src/data_receiver.cpp
	src/main.cpp)
	
add_executable(program_1 ${SOURCES} ${HEADERS})
