#include "TestModule.h"
#include <iostream>

using namespace AzNetwork;

AzNetwork::TestModule::TestModule() : m_service(), m_pThread()
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
	isOperation = true;
}

AzNetwork::TestModule::~TestModule()
{
	std::cout << __PRETTY_FUNCTION__ << std::endl;
}
/*
TestModule& TestModule::GetInstance()
{
	static TestModule instance;
	return instance;
}
*/

void AzNetwork::TestModule::start()
{
	//m_service.run();
	//m_service.poll();

	if (m_pThread)
	{
		return;
	}

	m_pThread.reset(new boost::thread(boost::bind(&boost::asio::io_service::run, boost::ref(m_service))));
	
#if 0
	for (int nIndex = 0; nIndex < AD_THREAD_COUNT; ++nIndex)
	{
		m_service.post(boost::bind(&TestModule::PrintThreadsInfo, this, 100));
	}

	for (int nIndex = 0; nIndex < AD_THREAD_COUNT; ++nIndex)
	{
		io_threads.create_thread(boost::bind(&boost::asio::io_service::run, &m_service));
	}
#endif
}

void AzNetwork::TestModule::stop()
{
	if (!m_pThread)
	{
		return;
	}
	isOperation = false;
	m_service.stop();
	m_pThread->join();

	//io_threads.join_all();
	m_service.reset();
	m_pThread.reset();
}

void AzNetwork::TestModule::suspend()
{
}

void AzNetwork::TestModule::PrintThreadsInfo(int nCnt)
{
	std::string curThreadId = boost::lexical_cast<std::string>(boost::this_thread::get_id());

	for (int nIndex = 0; nIndex < nCnt; ++nIndex)
	{
		printf("[%d -> current thread id : %s] \n", nIndex, curThreadId.c_str());
		boost::this_thread::sleep_for(boost::chrono::milliseconds(1000));
	}
}

void AzNetwork::TestModule::do_print(int nCnt)
{
	int v = nCnt;

	boost::function<void(int)> printerHandler = [&](int nCnt) {
		for (int i = 1; i <= nCnt; ++i)
		{
			if (isOperation == false)
			{
				std::cout << "... forcibly finish handler" << std::endl;
			}
			std::cout << __PRETTY_FUNCTION__ << "called and loop : " << i << std::endl;
			boost::this_thread::sleep_for(boost::chrono::milliseconds(1000));
		}
	};
	
	m_service.post(boost::bind(printerHandler, nCnt));

	//Printhandler(nCnt);
#if 0
	boost::function<void(int)> printerHandler = [](int nCnt) {
		for (int i = 0; i < nCnt; ++i)
		{
			std::cout << __PRETTY_FUNCTION__ << " : called and loop : " << i << std::endl;
			boost::this_thread::sleep_for(boost::chrono::milliseconds(1000));
		}
	};
	m_service.post(boost::bind(printerHandler, nCnt));
#endif
}

void AzNetwork::TestModule::Printhandler(int nCnt)
{
	for (int i = 1; i <= nCnt; ++i)
	{
		std::cout << __PRETTY_FUNCTION__ << " : called and loop : " << i << std::endl;
		boost::this_thread::sleep_for(boost::chrono::milliseconds(1000));
	}
}

int AzNetwork::TestModule::foo(int n)
{
	return n;
}

int AzNetwork::TestModule::goo(int n)
{
	return n;
}

void AzNetwork::TestModule::Test()
{
	int(AzNetwork::TestModule:: * fcnPtr)(int) = &AzNetwork::TestModule::foo;
	int(* fcnPtr2)(int) = &goo;

	std::cout << "[fcnPtr] : " << fcnPtr2(21) << std::endl;
	std::cout << "[fcnPtr] : " << &fcnPtr << std::endl;
}
