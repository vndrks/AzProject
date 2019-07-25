#include <openssl/sha.h>


namespace AzComponents
{
class AcEncoder
{
public:
	AcEncoder();
	virtual ~AcEncoder();

private:
	struct AsEncoderImpl;
	AsEncoderImpl* m_EncoderImpl;

public:
	void* GetEncoder();


};
}