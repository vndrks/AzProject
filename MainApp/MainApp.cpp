// MainApp.cpp : 애플리케이션의 진입점을 정의합니다.
//

#include "MainApp.h"
#include <AzNetwork/TestModule.h>
#include <TestModule/AsyncInOut/TestSingleThread.h>
#include <TestModule/AsyncInOut/TestMultiThread.h>

#include <TestModule/Block/TestBlockHeader.h>
#include <TestModule/Crypto/TestSha256.h>
#include <TestModule/Crypto/TestGenKeyPair.h>

#include <AzNetwork/AcIOService.h>
#include <AcApplication.h>

using namespace std;
using namespace AzNetwork;

int main(int argc, char* argv[])
{
	AppBase::App().Startup();
	AppBase::App().Execute();
	TestModule::TestGenKeyPair genKeyPair;
	int nRet = genKeyPair.GenerateKey();

	printf("Result : %d\n", nRet);
	
	/*
	AzNetwork::AcIOService service;
	service.test();
	*/
	//TestModule::TestMultiThread t;
	//TestModule::TestBlockHeader bheader;

	/*t.Start();

	while (1)
	{
		std::cout << "in while loop ... " << std::endl;
		char chCommand;
		std::cin.get(chCommand);

		if (chCommand == 'x')
		{
			break;
		}
	}

	t.Stop();
	*/
	cout << "Finished. AZ Module v0.01." << endl;
	
	return 0;
}
