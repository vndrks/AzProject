#include <iostream>

#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <boost/scoped_ptr.hpp>

namespace TestModule
{
	class TestSingleThread
	{
	public:
		TestSingleThread();
		virtual ~TestSingleThread();

	private:
		boost::asio::io_service				m_service;
		boost::scoped_ptr<boost::thread>	m_pThread;
		
		bool m_isOperation;

	public:
		void	PrintThreadInfo(int nThreadCnt);
		void	Start();
		void	Stop();
	};
}