cmake_minimum_required (VERSION 3.8)
project(AzNetwork)

file(GLOB HEADER_FILES
	AdConfig.h
	AcIOService.h
	)

file(GLOB SOURCE_FILES
	TestModule.cpp
	AcIOService.cpp
	)
#set(Boost_USE_STATIC_LIBS OFF) 
#set(Boost_USE_MULTITHREADED ON)  
#set(Boost_USE_STATIC_RUNTIME OFF) 

#target_compile_features(AzNetwork PRIVATE cxx_range_for)

find_package(Boost 1.70.0 REQUIRED COMPONENTS thread
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

set(Module_AzNetwork ${HEADER_FILES} ${SOURCE_FILES})

if(Boost_FOUND)
	message(STATUS "Boost_VERSION=" ${Boost_VERSION})
	message(STATUS "Boost_LIBRARIES=" ${Boost_LIBRARIES})
	message(STATUS "Boost_LIBRARY_DIRS=" ${Boost_LIBRARY_DIRS})
	message(STATUS "Boost_INCLUDE_DIRS=" ${Boost_INCLUDE_DIRS})

    message("[" ${PROJECT_NAME} ] Boost found)
	include_directories(${Boost_INCLUDE_DIRS})
	add_library(AzNetwork SHARED ${Module_AzNetwork})
	target_link_libraries(AzNetwork LINK_PUBLIC ${Boost_LIBRARIES} pthread)

	set(${PROJECT_NAME}_INCLUDE_DIRS} ${Boost_INCLUDE_DIRS}) 
endif()

