#include "AcApplication.h"
#include <iostream>



using namespace AppBase;

AcApplication::AcApplication()
	:m_ioService(std::make_shared<boost::asio::io_service>())
{
	std::cout << "[Constructor] " << __PRETTY_FUNCTION__ << std::endl;
}

AcApplication::~AcApplication()
{
	std::cout << "[Destructor] " << __PRETTY_FUNCTION__ << std::endl;
}

AcApplication& AcApplication::Instance()
{
	static AcApplication instance;
	return instance;
}

void AcApplication::Startup()
{
	std::shared_ptr<boost::asio::io_service> ioService = std::make_shared<boost::asio::io_service>();

	// todo ...

	// end
	std::thread sigThread([ioService]() { ioService->run(); });

	//sigThread.join();
	sigThread.detach();

}

void AcApplication::Execute()
{
	TestPrint();
	//m_ioService->run();
}

void AcApplication::TestPrint()
{
	printf("TestTest\n");

	int nCnt = 0;
	while (1)
	{
		printf("Test%d \n", nCnt);
		if (nCnt == 10000) break;
		++nCnt;
	}
	
}

AcApplication& AppBase::App()
{
	return AcApplication::Instance();
}
