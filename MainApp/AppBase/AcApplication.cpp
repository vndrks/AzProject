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

	std::shared_ptr<boost::asio::signal_set> sigSetInt(new boost::asio::signal_set(*m_ioService, SIGINT));
	
	sigSetInt->async_wait([sigSetInt, this](const boost::system::error_code& err, int num) {
		char chTmp[1024];
		printf("ERROR : %s \n", err.message(chTmp, sizeof(chTmp)));
		sigSetInt->cancel();
	});
	// todo ...

	
	
	//std::thread thread([ioService]() { ioService->run(); });
	std::thread thread([this]() { nRt = TestPrint(1); });

	std::thread thread2([this]() {nRt = TestPrint(2); });
	
	
//	thread.join();
//	thread2.join();
	
	thread.detach();
	thread2.detach();
	
	// end
	printf("###### %d \n", nRt);
}

void AcApplication::Execute()
{
	//TestPrint();
	//m_ioService->run();
}

int AcApplication::TestPrint(int nThreadNum)
{
	printf("TestTest\n");

	int nCnt = 0;
	while (1)
	{
		sleep(1);
		printf("[%d] Test%d \n", nThreadNum, nCnt);
		if (nCnt == 10000)
		{
			return nCnt;
		}
		++nCnt;
	}
	
	return nCnt;
}

AcApplication& AppBase::App()
{
	return AcApplication::Instance();
}
