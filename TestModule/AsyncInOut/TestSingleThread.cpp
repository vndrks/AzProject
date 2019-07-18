#include "TestSingleThread.h"

using namespace TestModule;

TestSingleThread::TestSingleThread()
{
	std::cout << "[ " << __PRETTY_FUNCTION__ << " ]" << std::endl;
	m_isOperation = true;
}

TestSingleThread::~TestSingleThread()
{
	std::cout << "[ " << __PRETTY_FUNCTION__ << " ]" << std::endl;
}

void TestSingleThread::PrintThreadInfo(int nLoopCnt)
{
	std::cout << "[ " << __PRETTY_FUNCTION__ << " ]" << std::endl;

	boost::function<void(int)> printerHandler = [&](int nThreadCnt) {
		for (int nIdx = 1; nIdx <= nThreadCnt; ++nIdx)
		{
			if (m_isOperation == false)
			{
				std::cout << "Forcibly finish handler" << std::endl;
				break;
			}
			
			std::cout << __PRETTY_FUNCTION__ << " : called and loop : " << nIdx << std::endl;
			boost::this_thread::sleep_for(boost::chrono::seconds(1));
		}
	};

	m_service.post(boost::bind(printerHandler, nLoopCnt));
}

void TestSingleThread::Start()
{
	if (m_pThread) return;
	
	m_pThread.reset(new boost::thread(boost::bind(&boost::asio::io_service::run, boost::ref(m_service))));
}

void TestSingleThread::Stop()
{
	if (!m_pThread) return;

	m_isOperation = false;
	m_service.stop();
	m_pThread->join();

	m_service.reset();
	m_pThread.reset();
}
