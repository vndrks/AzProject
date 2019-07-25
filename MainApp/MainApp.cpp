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
#include <AzComponents/AzC_Crypto/AcSha256.h>

#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/serialization/base_object.hpp>

using namespace std;
using namespace AzNetwork;

int main(int argc, char* argv[])
{

	AzComponents::AcSha256 aa(10);
	
	ofstream output("./output.txt", ios::binary);

	boost::archive::text_oarchive oar(output);
	oar << aa;
	output.close();

	ifstream input("./output.txt", ios::binary);
	boost::archive::text_iarchive iar(input);

	AzComponents::AcSha256 aaa;
	iar >> aaa;
	std::string strTmp = aaa.getHash();
	printf("#######111 Hash : %s \n", strTmp.c_str());



	
	

	//TestModule::TestSha256 sha256;

	/*
	AppBase::App().Startup();
	AppBase::App().Execute();
	TestModule::TestGenKeyPair genKeyPair;
	int nRet = genKeyPair.GenerateKey();

	printf("Result : %d\n", nRet);

	unsigned int nCnt = 0;
	while (1)
	{
		sleep(1);
		++nCnt;

		if (nCnt > 20)
			break;
	}
	*/
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
