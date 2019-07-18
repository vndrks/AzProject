#include <stdio.h>
#include <memory>

#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <boost/smart_ptr.hpp>
#include <boost/thread.hpp>

namespace AzNetwork
{
	class AcIOService
	{
	public:
		AcIOService();
		virtual ~AcIOService();

	private:
		boost::asio::io_service				m_service;
		boost::scoped_ptr<boost::thread>	m_pThread;
		
		//std::shared_ptr<void()>	testFunc(fun, del);

	public:
		void	Start();
		bool	Stop();

		bool	PrintThreadInfo(int nCnt);
		
		
		void	test();
	};
}