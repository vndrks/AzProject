#include "AcIOService.h"

#include <ios>
#include <stdio.h>
#include <iostream>


#include <boost/date_time.hpp>

using namespace AzNetwork;

AcIOService::AcIOService() : m_service(), m_pThread()
{

}

AcIOService::~AcIOService()
{
}

void AcIOService::Start()
{
	if (m_pThread)
	{
		return;
	}

	m_pThread.reset(
		new boost::thread(boost::bind(&boost::asio::io_service::run, boost::ref(m_service)))
	);
	

}

bool AcIOService::Stop()
{
	if (!m_pThread)
	{
		return false;
	}
	
	m_service.stop();
}

bool AcIOService::PrintThreadInfo(int nCnt)
{
	return false;
}


void AcIOService::test()
{
	std::ios::sync_with_stdio(true);

	boost::posix_time::ptime t1 = boost::posix_time::microsec_clock::local_time();
	for (int i = 0; i < 1000000; ++i)
	{
		std::cout << "A" << i;printf("a%d", i);std::cout << std::endl;
	}
	boost::posix_time::ptime t2 = boost::posix_time::microsec_clock::local_time();

	boost::posix_time::time_duration diff = t2 - t1;
	


	std::cout << "[milli] t2 - t1 = " << diff.total_milliseconds() << std::endl;
	std::cout << "[micro] t2 - t1 = " << diff.total_microseconds() << std::endl;
}
