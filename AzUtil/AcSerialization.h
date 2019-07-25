
#include <boost/serialization/base_object.hpp>

#include "AzComponents/AzC_Crypto/AcSha256.h"

namespace AzUtil
{

class AzSerialization
{
public:
	AzSerialization();
	virtual ~AzSerialization();

private:
	template <class Archive>
	void serialize(Archive& ar, const unsigned int version)
	{
		ar& boost::serialization::base_object<AzComponents::AcSha256>(*this);
	}


};

}