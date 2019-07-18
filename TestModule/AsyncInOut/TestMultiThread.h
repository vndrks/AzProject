#include <iostream>

#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <boost/chrono.hpp>

namespace TestModule
{
	class TestMultiThread
	{
	public:
		TestMultiThread();
		virtual ~TestMultiThread();

	public:
		void PrintThreadInfo(int nCnt);
		void Start();
		void Stop();

	private:
		boost::asio::io_service	m_service;
		boost::thread_group		m_ioThread;
		boost::thread_group		m_printThread;

		boost::asio::io_service::strand m_strand1;
		boost::asio::io_service::strand m_strand2;

		boost::asio::io_service::work m_work;
	};
}