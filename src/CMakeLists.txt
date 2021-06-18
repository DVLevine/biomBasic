add_library(
	biomechBasic
	STATIC
	biomechTime.cpp
	biomechTime.h
)

target_include_directories(biomechBasic PRIVATE usr/include)
