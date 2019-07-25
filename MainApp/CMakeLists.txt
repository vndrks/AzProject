cmake_minimum_required (VERSION 3.8)
project(MainApp)

#file(GLOB HEADER_FILES
#	"AppBase/*.h"
#	)
#file(GLOB SOURCE_FILES
#	"AppBase/*.cpp"
#	)

file(GLOB HEADER_FILES
	"AppBase/AcApplication.h"
	)

file(GLOB SOURCE_FILES
	"AppBase/AcApplication.cpp"
	)

find_package(Boost 1.70.0 COMPONENTS
	thread
    system
	REQUIRED
)

add_executable (MainApp "MainApp.cpp" "MainApp.h" ${HEADER_FILES} ${SOURCE_FILES})
target_compile_features(MainApp PRIVATE cxx_range_for)

include_directories(.. ./AppBase/)
target_link_libraries(MainApp LINK_PUBLIC AzChain AzComponents AzNetwork AzUtil TestModule_Async TestModule_Block TestModule_Crypto ${Boost_LIBRARIES})




