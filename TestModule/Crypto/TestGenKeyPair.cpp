#include "TestGenKeyPair.h"

#include <openssl/ec.h>
#include <openssl/obj_mac.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/err.h>

using namespace TestModule;

TestGenKeyPair::TestGenKeyPair()
{

}

TestGenKeyPair::~TestGenKeyPair()
{
}

int TestGenKeyPair::GenerateKey()
{
	int nFuncStat = 1;
	EC_KEY* pEcKey = EC_KEY_new_by_curve_name(NID_secp256k1);

	if (!pEcKey)
	{
		nFuncStat = -1;
	}
	if (!EC_KEY_generate_key(pEcKey))
	{
		nFuncStat = -1;
	}

	const BIGNUM* pRes;
	pRes = EC_KEY_get0_private_key(pEcKey);
	printf("Private : %s\n", BN_bn2hex(pRes));

	const EC_GROUP* pGroup;
	pGroup = EC_KEY_get0_group(pEcKey);

	const EC_POINT* pPubKey = NULL;
	pPubKey = EC_KEY_get0_public_key(pEcKey);

	BN_CTX *pCtx;
	pCtx = BN_CTX_new();
	point_conversion_form_t form = POINT_CONVERSION_COMPRESSED;
	printf("public : %s\n", EC_POINT_point2hex(pGroup, pPubKey, form, pCtx));

	return nFuncStat;
}

int TestGenKeyPair::TestGenerateRSAKey()
{
	size_t priLen;
	size_t pubLen;
	char* pPriKey;
	char* pPubKey;

	int nRet = 0;
	RSA* r = NULL;
	BIGNUM* nBne = NULL;
	BIO* pBioPublic = NULL;
	BIO* pBioPrivate = NULL;
	int nBits = 2048;
	unsigned long e = RSA_F4;

	RSA * pubRsa = NULL;
	RSA * priRsa = NULL;

	EVP_PKEY* evpPubKey = NULL;
	EVP_PKEY* evpPriKey = NULL;

	BIO* pubKeyBio = NULL;
	BIO* priKeyBio = NULL;

	nBne = BN_new();
	nRet = BN_set_word(nBne, e);
	if (nRet != 1)
	{
		goto free_all;
	}

	r = RSA_new();
	nRet = RSA_generate_key_ex(r, nBits, nBne, NULL);

	if (nRet != 1)
	{
		goto free_all;
	}

	pBioPublic = BIO_new(BIO_s_mem());
	nRet = PEM_write_bio_RSAPublicKey(pBioPublic, r);
	if (nRet != 1)
	{
		goto free_all;
	}

	pBioPrivate = BIO_new(BIO_s_mem());
	nRet = PEM_write_bio_RSAPrivateKey(pBioPrivate, r, NULL, NULL, 0, NULL, NULL);
	if (nRet != 1)
	{
		goto free_all;
	}

	priLen = BIO_pending(pBioPrivate);
	pubLen = BIO_pending(pBioPublic);

	pPriKey = (char*)malloc(priLen + 1);
	pPubKey = (char*)malloc(pubLen + 1);

	BIO_read(pBioPrivate, pPriKey, priLen);
	BIO_read(pBioPublic, pPubKey, pubLen);

	pPriKey[priLen] = '\0';
	pPubKey[pubLen] = '\0';

	printf("PrivateKey : \n\n%s PublicKey : \n\n%s\n", pPriKey, pPubKey);

	pubKeyBio = BIO_new_mem_buf((void*)pPubKey, pubLen);
	if (pubKeyBio == NULL)
	{
		return -1;
	}
	//evpPubKey = PEM_read_bio_PUBKEY(pubKeyBio, &evpPubKey, NULL, NULL);
	pubRsa = PEM_read_bio_RSAPublicKey(pubKeyBio, &pubRsa, NULL, NULL);

	if (pubRsa == NULL)
	{
		char chBuf[128];
		ERR_error_string(ERR_get_error(), chBuf);
		printf("Error reading pub key : %s\n", chBuf);
	}
	evpPubKey = EVP_PKEY_new();
	EVP_PKEY_assign_RSA(evpPubKey, pubRsa);

	priKeyBio = BIO_new_mem_buf((void*)pPriKey, priLen);
	if (priKeyBio == NULL)
	{
		return -1;
	}

	//evpPriKey = PEM_read_bio_PrivateKey(priKeyBio, &evpPriKey, NULL, NULL);
	//if (evpPriKey == NULL)
	priRsa = PEM_read_bio_RSAPrivateKey(priKeyBio, &priRsa, NULL, NULL);
	if(priRsa == NULL)
	{
		char chBuf[120];
		ERR_error_string(ERR_get_error(), chBuf);
		printf("Error reading private key:%s\n", chBuf);
	}
	evpPriKey = EVP_PKEY_new();
	EVP_PKEY_assign_RSA(evpPriKey, priRsa);

	BIO_free(pubKeyBio);
	BIO_free(priKeyBio);
	
free_all:
	BIO_free_all(pBioPublic);
	BIO_free_all(pBioPrivate);
	RSA_free(r);
	BN_free(nBne);

	return ( nRet == 1 );
}

