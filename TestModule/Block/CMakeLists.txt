cmake_minimum_required(VERSION 3.8)
project(TestModule)

file(GLOB HEADER_FILE 
	TestBlockHeader.h
	TestBlock.h)
file(GLOB SOURCE_FILE 
	TestBlockHeader.cpp
	TestBlock.cpp)

find_package(Boost 1.70.0 COMPONENTS 
    date_time
    REQUIRED
)

set(TesetModule_TestBlock_SRC ${HEADER_FILE} ${SOURCE_FILE})

include_directories(${Boost_INCLUDE_DIRS})
add_library(TestModule_Block SHARED ${TesetModule_TestBlock_SRC})
target_link_libraries(TestModule_Block LINK_PUBLIC ${Boost_LIBRARIES} pthread)

set(${PROJECT_NAME}_INCLUDE_DIRS ${Boost_INCLUDE_DIRS})