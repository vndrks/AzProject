#include <vector>

namespace TestModule
{
	typedef std::vector<char> AD_BYTES;

	class TestGenKeyPair
	{
	public:
		TestGenKeyPair();
		virtual ~TestGenKeyPair();
	

	public:
		int GenerateKey();
		int TestGenerateRSAKey();
	};
}