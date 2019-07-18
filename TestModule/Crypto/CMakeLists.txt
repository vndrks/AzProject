cmake_minimum_required(VERSION 3.8)
project (TestModule)

file(GLOB HEADER_FILE
	TestSha256.h
	TestGenKeyPair.h
	TestPublicKey.h
	TestPrivateKey.h
	)
file(GLOB SOURCE_FILE
	TestSha256.cpp
	TestGenKeyPair.cpp
	TestPublicKey.cpp
	TestPrivateKey.cpp
	)


set(TesetModule_TestCrypto_SRC ${HEADER_FILE} ${SOURCE_FILE})
set(OPENSSL_ROOT_DIR "/usr/local/ssl")
set(OPENSSL_INCLUDE_DIR "/usr/local/ssl/include")

find_package(OpenSSL REQUIRED)

if(OPENSSL_FOUND)
	message(STATUS "[OpenSSL Found]")
	message(STATUS "[OPENSSL_INCLUDE_DIR] : " ${OPENSSL_INCLUDE_DIR})

	include_directories(${OPENSSL_INCLUDE_DIR})
	add_library(TestModule_Crypto SHARED ${TesetModule_TestCrypto_SRC})
	target_link_libraries(TestModule_Crypto OpenSSL::SSL OpenSSL::Crypto)
	#target_include_directories(TestModule_Crypto PUBLIC ${OPENSSL_INCLUDE_DIR})
	
	set(${PROJECT_NAME}_INCLUDE_DIRS ${OPENSSL_INCLUDE_DIR})
endif()