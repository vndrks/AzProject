#include "AcEncoder.h"



using namespace AzComponents;

AcEncoder::AcEncoder()
{
}

AcEncoder::~AcEncoder()
{
}

struct AcEncoder::AsEncoderImpl
{
	SHA256_CTX ctxSHA256;
};

