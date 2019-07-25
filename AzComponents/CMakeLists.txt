cmake_minimum_required (VERSION 3.8)
project(AzComponents)

file(GLOB HEADER_FILES
	AzC_Crypto/AcSha256.h
	AzC_Crypto/AcEncoder.h
	test.h
	)
file(GLOB SOURCE_FILES
	AzC_Crypto/AcSha256.cpp
	AzC_Crypto/AcEncoder.cpp
	)

set(AzComponents_SRC ${HEADER_FILES} ${SOURCE_FILES})
set(OPENSSL_ROOT_DIR "/usr/local/ssl")
set(OPENSSL_INCLUDE_DIR "/usr/local/ssl/include")

#find_package(Boost 1.70.0 COMPONENTS
#	thread
#	system
#	OpenSSL
#	REQUIRED)

find_package(OpenSSL REQUIRED)

if(OPENSSL_FOUND)
	message(STATUS "[AzComponents][Open SSL] found")
	message(STATUS "[AzComponents][OPENSSL_INCLUDE_DIR] " ${OPENSSL_INCLUDE_DIR})

	include_directories(${OPENSSL_INCLUDE_DIR})
	add_library(AzComponents SHARED ${AzComponents_SRC})
	target_link_libraries(AzComponents OpenSSL::SSL OpenSSL::Crypto)

	set(${PROJECT_NAME}_INCLUDE_DIRS ${OPENSSL_INCLUDE_DIR})
endif()