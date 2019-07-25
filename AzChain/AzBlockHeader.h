#include <iostream>
#include <vector>

namespace AzChain
{

class AzBlockHeader
{
public:
	AzBlockHeader();
	virtual ~AzBlockHeader();

private:
	uint32_t			m_nBlockNumber;
	time_t				m_timestamp;
	char*				m_parentHash;

	//std::vector<char*>	m_lParentHash;


};

}