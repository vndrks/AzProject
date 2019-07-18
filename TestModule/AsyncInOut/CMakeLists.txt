cmake_minimum_required(VERSION 3.8)
project(TestModule)

file(GLOB HEADER_FILES 
	TestMultiThread.h
	TestSingleThread.h
	)
file(GLOB SOURCE_FILES
	TestMultiThread.cpp
	TestSingleThread.cpp
	)

find_package(Boost 1.70.0 COMPONENTS thread
    date_time
    filesystem
    system
    program_options
    serialization
    chrono
    unit_test_framework
    context
    locale
    iostreams REQUIRED
)

set(TestModule_AsyncInOut_SRC ${HEADER_FILES} ${SOURCE_FILES})

if(Boost_FOUND)
    message(STATUS "[Boost version      ] " ${Boost_VERSION})
    message(STATUS "[Boost Libraries    ] " ${Boost_LIBRARIES})
    message(STATUS "[Boost Lib Dirs     ] " ${Boost_LIBRARY_DIRS})
    message(STATUS "[Boost Include Dirs ] " ${Boost_INCLUDE_DIRS})

    message("[" ${PROJECT_NAME} "] " Boost found)
    include_directories(${Boost_INCLUDE_DIRS})
    add_library(TestModule_Async SHARED ${TestModule_AsyncInOut_SRC})
    target_link_libraries(TestModule_Async LINK_PUBLIC ${Boost_LIBRARIES} pthread)

    set(${PROJECT_NAME}_INCLUDE_DIRS ${Boost_INCLUDE_DIRS})

endif()