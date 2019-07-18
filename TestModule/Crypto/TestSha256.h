#include <iostream>
#include <stdio.h>
#include <string.h>

namespace TestModule
{
	class TestSha256
	{
	public:
		TestSha256();
		virtual ~TestSha256();

	public:
		int TestGetPrivateKey();
		int CreateSignature(unsigned char* strHash);
	};
}