#include "card.h"
#include "block.h"

std::istream & operator>>(std::istream& is, card& rhs)
{
	//std::for_each(rhs.begin(), rhs.end(), [&is](block& s) {is>>s; });
	return is;
}
