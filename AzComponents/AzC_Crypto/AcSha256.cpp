#include "AcSha256.h"

#include <stdio.h>
#include <string.h>



using namespace AzComponents;


AcSha256::AcSha256(int nTest)
{
	//SHA256_CTX ctxSHA256;
	SHA256_Init(&_m_ctxSHA256);
	Update("TestSha256.");
	Final();
}

AcSha256::~AcSha256()
{
}

bool AcSha256::Update(char* pStr)
{
	return SHA256_Update(&_m_ctxSHA256, pStr, strlen(pStr));
}

bool AcSha256::Final()
{
	unsigned char digestSHA256[SHA256_DIGEST_LENGTH];

	bool isResult = SHA256_Final(digestSHA256, &_m_ctxSHA256);

	char chMdString[SHA256_DIGEST_LENGTH * 2 + 1];
	for (int nIdx = 0; nIdx < sizeof(digestSHA256); ++nIdx)
	{
		sprintf(&chMdString[nIdx * 2], "%02x", (unsigned int)digestSHA256[nIdx]);
	}
	std::string str(chMdString);
	_m_strHash = str;
	printf("##### %s\n", _m_strHash.c_str());

	/*
	std::string ss = ToHex(str.c_str(), str.length());
	printf("##### ToHex : %s\n", ss.c_str());

	char chBuf[64];
	size_t tt = FromHex(str.c_str(), chBuf, str.length());
	printf("##### FromHex : %s\n", chBuf);
	*/

	
	return isResult;
}

std::string AcSha256::getHash()
{
	return _m_strHash.c_str();
}

#if 0

std::string AcSha256::ToHex(const char* d, uint32_t s)
{
	std::string r;
	const char* toHex = "0123456789abcdef";
	uint8_t* c = (uint8_t*)d;
	for (uint32_t i = 0; i < s; ++i)
		(r += toHex[(c[i] >> 4)]) += toHex[(c[i] & 0x0f)];
	return r;
}

uint8_t from_hex(char c) {
	if (c >= '0' && c <= '9')
	{
		return c - '0';
	}
	else if (c >= 'a' && c <= 'f')
	{
		return c - 'a' + 10;
	}
	else if (c >= 'A' && c <= 'F')
	{
		return c - 'A' + 10;
	}
		
	else
	{

	}

	return 0;
}



size_t AcSha256::FromHex(const std::string strHex, char* outData, size_t outDataLen)
{
	std::string::const_iterator i = strHex.begin();
	uint8_t* out_pos = (uint8_t*)outData;
	uint8_t* out_end = out_pos + outDataLen;
	
	while (i != strHex.end() && out_end != out_pos)
	{
		*out_pos = from_hex(*i) << 4;
		++i;
		if (i != strHex.end()) {
			*out_pos |= from_hex(*i);
			++i;
		}
		++out_pos;
	}
return out_pos - (uint8_t*)outData;}


#endif // !1