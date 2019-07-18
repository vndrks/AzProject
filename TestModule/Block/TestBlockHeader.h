#include <iostream>
#include <vector>

#include <boost/date_time.hpp>

namespace TestModule
{
	struct AsBlockHeader
	{
		time_t timeStamp;
		uint32_t nBlockNum;
		//unsigned int nBlockNum;
		char* sAccountName;
	};

	struct AsSignedBlockHeader : AsBlockHeader
	{
		
	};

	class TestBlockHeader
	{
	public:
		TestBlockHeader();
		virtual ~TestBlockHeader();

		void test();
	};

	
}