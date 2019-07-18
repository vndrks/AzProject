#include "TestBlockHeader.h"

using namespace TestModule;

TestBlockHeader::TestBlockHeader()
{
	boost::posix_time::ptime t1 = boost::posix_time::second_clock::local_time();

	sleep(1);

	boost::posix_time::ptime t2 = boost::posix_time::second_clock::local_time();

	std::cout << "t2 - t1 = " << t2 - t1 << std::endl;
}

TestBlockHeader::~TestBlockHeader()
{

}

void TestBlockHeader::test()
{

}
