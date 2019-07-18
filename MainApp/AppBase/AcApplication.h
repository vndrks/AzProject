#include <memory>

#include "boost/asio.hpp"

namespace AppBase
{
class AcApplication
{
public:
	AcApplication();
	virtual ~AcApplication();

public:
	static AcApplication& Instance();
	//AcApplication& App();

	void	Startup();
	void	Execute();

	static void	TestPrint();

private:
	std::shared_ptr<boost::asio::io_service> m_ioService;
};

AcApplication& App();
}