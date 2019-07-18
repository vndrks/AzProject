#include "TestSha256.h"

#include <openssl/sha.h>
#include <openssl/ec.h>
#include <openssl/ecdsa.h>
#include <openssl/obj_mac.h>

using namespace TestModule;
using namespace std;

TestSha256::TestSha256()
{
	unsigned char digestSHA256[SHA256_DIGEST_LENGTH];
	char chStr[] = "TestSha256.";

	SHA256_CTX ctxSHA256;
	
	//@ Sol.01
	/*
	SHA256_Init(&ctxSHA256);
	SHA256_Update(&ctxSHA256, chStr, strlen(chStr));
	SHA256_Final(digestSHA256, &ctxSHA256);
	*/
	char chMdString[SHA256_DIGEST_LENGTH * 2 + 1];
	
	// @ Sol.02
	SHA256((unsigned char*)& chStr, strlen(chStr), (unsigned char*)& digestSHA256);

	for (int nCnt = 0; nCnt < SHA256_DIGEST_LENGTH; ++nCnt)
	{
		sprintf(&chMdString[nCnt * 2], "%02x", (unsigned int)digestSHA256[nCnt]);
	}

	std::cout << "\"" << chStr << "\" to SHA256 Digest : " << chMdString << endl;

	CreateSignature((unsigned char*)chMdString);
}

TestSha256::~TestSha256()
{
}


int TestSha256::TestGetPrivateKey()
{
	int nFncStatus = 1;

	return nFncStatus;
}

int TestSha256::CreateSignature(unsigned char* strHash)
{
	int fncStatus = 0;
	EC_KEY* pEcKey = EC_KEY_new();

	if (NULL == pEcKey)
	{
		fncStatus = -1;
	}
	else
	{
		EC_GROUP* pEcGroup = EC_GROUP_new_by_curve_name(NID_secp256k1);
		int nEcKeyGroupStatus = EC_KEY_set_group(pEcKey, pEcGroup);
		const int nEcKeyGroupSuccess = 1;

		if (nEcKeyGroupSuccess != nEcKeyGroupStatus)
		{
			printf("Failed to set group for ECKey\n");
			fncStatus = -1;
		}
		else
		{
			const int nSuccess = 1;
			int nGenStat = EC_KEY_generate_key(pEcKey);
			if (nGenStat != nSuccess)
			{
				printf("Failed to generate ECKEY \n");
				fncStatus = -1;
			}
			else
			{
				ECDSA_SIG* signature = ECDSA_do_sign(strHash, strlen((char*)strHash), pEcKey);

				if (NULL == signature)
				{
					printf("Failed to do Signature \n");
					fncStatus = -1;
				}
				else
				{
					int nVerifyStat = ECDSA_do_verify(strHash, strlen((char*)strHash), signature, pEcKey);
					const int nVerifySuccess = 1;

					if (nVerifySuccess != nVerifyStat)
					{
						printf("Failed to do verify \n");
						fncStatus = -1;
					}
					else
					{
						printf("Verified EC sign \n");
						fncStatus = 1;
					}
				}
			}
			
			EC_GROUP_free(pEcGroup);
		}
		EC_KEY_free(pEcKey);
	}
	return fncStatus;
}
