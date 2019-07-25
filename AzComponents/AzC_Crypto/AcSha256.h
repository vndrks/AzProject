#include <string>
#include <stdint.h>

#include <boost/serialization/base_object.hpp>
#include "AcEncoder.h"

namespace AzComponents
{

class AcSha256
{
public:
	AcSha256() = default;
	AcSha256(int nTest);
	virtual ~AcSha256();
	
public:
	bool			Update(char* pStr);
	bool			Final();
	std::string		getHash();

private:
	SHA256_CTX		_m_ctxSHA256;
	uint64_t		_hash[4];	// 8byte x 4 = 32byte
	std::string		_m_strHash;

	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive& ar, const unsigned int version)
	{
		//ar& _m_ctxSHA256;
		ar& _hash;
		ar& _m_strHash;
	}

	




#if 0
	std::string ToHex(const char* d, uint32_t s);
	size_t FromHex(const std::string str, char* outData, size_t outDataSize);
#endif
};

}