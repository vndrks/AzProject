#include "TestMultiThread.h"
#include <boost/lexical_cast.hpp>


using namespace TestModule;

TestMultiThread::TestMultiThread()
	: m_service(), m_strand1(m_service), m_strand2(m_service), m_work(m_service)
{
	std::cout << "[ " << __PRETTY_FUNCTION__ << " ]" << std::endl;
}

TestMultiThread::~TestMultiThread()
{
	std::cout << "[ " << __PRETTY_FUNCTION__ << " ]" << std::endl;
}

void TestMultiThread::PrintThreadInfo(int nCnt)
{
	std::string curThreadId = boost::lexical_cast<std::string>(boost::this_thread::get_id());
	for (int nNum = 0; nNum < nCnt; ++nNum)
	{
		std::printf("[%d -> current Thread ID : %s] \n", nNum, curThreadId.c_str());
		boost::this_thread::sleep_for(boost::chrono::milliseconds(1000));
	}
}

void TestMultiThread::Start()
{
	std::cout << "[ " << __PRETTY_FUNCTION__ << " ]" << std::endl;

	//m_service.post(m_strand1.wrap(boost::bind(&TestMultiThread::PrintThreadInfo, this, 5)));
	//m_service.post(m_strand1.wrap(boost::bind(&TestMultiThread::PrintThreadInfo, this, 5)));

	for (int nThreanCnt = 0; nThreanCnt < 2; ++nThreanCnt)
	{
		m_printThread.create_thread(boost::bind(&TestMultiThread::PrintThreadInfo, this, 10));
	}
	for (int nThreanCnt = 0; nThreanCnt < 2; ++nThreanCnt)
	{
		m_ioThread.create_thread(boost::bind(&boost::asio::io_service::run, &m_service));
	}
}

void TestMultiThread::Stop()
{
	m_service.stop();
	m_printThread.join_all();
	m_ioThread.join_all();
	m_service.reset();
}
