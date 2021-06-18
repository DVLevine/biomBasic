cmake_minimum_required(VERSION 3.5.0)

project(biomechBasic)
set(CMAKE_CXX_FLAGS "-g -Wall")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(LIB_SYSTEM c stdc++)
set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -std=c++11")


add_subdirectory(src)

INSTALL(
	TARGETS biomechBasic 
	RUNTIME DESTINATION bin
	LIBRARY DESTINATION lib
	ARCHIVE DESTINATION lib
)


set(INSTALL_TARGETS src/biomechTime.h)

INSTALL(FILES ${INSTALL_TARGETS} DESTINATION include)