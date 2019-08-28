#include "card.h"
#include "block.h"



std::istream & operator>>(std::istream& is, card& rhs)
{
	std::string buf;
	while (std::getline(is, buf))
		//rhs.rawdata.push_back(block(&buf));
		if(buf.size()%32==0)
			rhs.rawdata.emplace_back(&buf);
	//{
	//	std::for_each(rhs.begin(), rhs.end(), [&buf](block s) {buf.size() == 32 ? (buf >> s).clear() : buf.clear(); });
	//}
	
	return is;
}

std::ostream& operator<<(std::ostream& os, const card& rhs)
{
	std::for_each(rhs.begin(), rhs.end(), [&os](block s) {os << s<< std::endl; });
	return os;
}

void print_test()
{
	std::cerr << "Hello from card.cpp" << std::endl;
}
