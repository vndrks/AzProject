#include <stdio.h>

#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/chrono.hpp>
#include <boost/smart_ptr.hpp>

#include "AdConfig.h"

namespace AzNetwork
{
	class TestModule
	{
	public:
		TestModule();
		virtual ~TestModule();

	private:
		boost::asio::io_service				m_service;
		boost::scoped_ptr<boost::thread>	m_pThread;
		
		boost::thread_group io_threads;

		bool	isOperation;

	public:
		//static	TestModule& GetInstance();
		void	start();
		void	stop();
		void	suspend();

		void	PrintThreadsInfo(int nCnt);
		void	do_print(int nCnt);
		void	Printhandler(int nCnt);

		int		foo(int n);
		static int		goo(int n);
		void	Test();
		
	};
}
