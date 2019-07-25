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

	int	TestPrint(int nThreadNum);
	
private:
	int nRt;
	std::shared_ptr<boost::asio::io_service> m_ioService;
};

AcApplication& App();
}