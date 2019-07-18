cmake_minimum_required (VERSION 3.8)
project(AzChain)

file(GLOB HEADER_FILES
	AzBlockHeader.h
	)

file(GLOB SOURCE_FILES
	AzBlockHeader.cpp
	)


set(Module_AzChain ${HEADER_FILES} ${SOURCE_FILES})
add_library(AzChain SHARED ${Module_AzChain})


