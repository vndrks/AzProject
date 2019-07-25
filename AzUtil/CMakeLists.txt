cmake_minimum_required (VERSION 3.8)
project(AzUtil)
file(GLOB HEADER_FILES
	AcSerialization.h
	)
file(GLOB SOURCE_FILES
	AcSerialization.cpp
	)

set(AzUtil_SRC ${HEADER_FILES} ${SOURCE_FILES})

find_package(Boost 1.70.0 COMPONENTS
    date_time
    filesystem
    system
    program_options
    serialization
    chrono
    unit_test_framework
    context
    locale
    REQUIRED
)

set(Module_AzUtil ${HEADER_FILES} ${SOURCE_FILES})

if(Boost_FOUND)
	message(STATUS "["${PROJECT_NAME}])
	message(STATUS "Boost_VERSION=" ${Boost_VERSION})
	message(STATUS "Boost_LIBRARIES=" ${Boost_LIBRARIES})
	message(STATUS "Boost_LIBRARY_DIRS=" ${Boost_LIBRARY_DIRS})
	message(STATUS "Boost_INCLUDE_DIRS=" ${Boost_INCLUDE_DIRS})

    message("[" ${PROJECT_NAME} ] Boost found)
	include_directories(${Boost_INCLUDE_DIRS} ../)
	add_library(AzUtil SHARED ${Module_AzUtil})
	target_link_libraries(AzUtil LINK_PUBLIC AzComponents ${Boost_LIBRARIES} pthread)

	set(${PROJECT_NAME}_INCLUDE_DIRS} ${Boost_INCLUDE_DIRS}) 
endif()


