#include "block.h"

block::block(std::string* s)
{
	if (check(s))
		construct(s);
}

block::block(const char* c)
{
	std::string buf = c;
	construct(&buf);
}

block block::change(const byte pos, byte value)
{
	dataset.at(pos) = value;
	return *this;
}

void block::construct(std::string* s)
{
	dataset.reserve(16);
	if (check(s))
		for (byte i = 0; i != 16; ++i)
			//dataset.at(i) = std::stoi(s->substr(int(i) * 2, 2), nullptr, 16);
			dataset.push_back(std::stoi(s->substr(int(i) * 2, 2), nullptr, 16));
}

void block::construct(const std::string* s)
{
	dataset.reserve(16);
	if (check(s))
		for (byte i = 0; i != 16; ++i)
			//dataset.at(i) = std::stoi(s->substr(int(i) * 2, 2), nullptr, 16);
			dataset.push_back(std::stoi(s->substr(int(i) * 2, 2), nullptr, 16));
}

std::vector<byte> block::str_to_vec(const std::string* s) 
{
	// условие для проверки длины входящей строки на случай строки нечетной длины
	std::vector<byte> buf(s->length()%2==0 ? s->length()/2 : s->length()/2+1,NULL);
	//std::cerr << "enter str_to_vec" << std::endl;
	//std::cerr << s->length() << std::endl;
	for (std::size_t i=0;i!=s->length()/2;++i)
		buf.at(i)= std::stoi(s->substr(int(i) * 2, 2), nullptr, 16);
	//std::cerr << buf.size() << std::endl;
	return buf;
}




int block::check(std::string* s)
{
	// скорее всего уже не нужно
	if (s->size() != 32)
	{
		std::cerr << "Uncorrected block length";
		return 2;
	}
	return 1;

}

int block::check(const std::string* s)
{
	// скорее всего уже не нужно
	if (s->size() != 32)
	{
		std::cerr << "Uncorrected block length";
		return 2;
	}
	return 1;
}

std::string block::subblock(const byte pos, const byte len)
{
	std::cerr << "enter func sub-block" << std::endl;
	std::stringstream stream;
	stream.fill('0');
	stream.flags(std::ios::hex);
	std::for_each(dataset.begin() + pos, dataset.begin() + pos + len, [&stream](const byte n)
	{
		stream.width(2);
		stream << +n;
	});
	std::cerr << "func sub-block completed" << std::endl;
	return stream.str();
}


std::ostream& operator<<(std::ostream& os, const block& obj)
{
	os.fill('0');
	os.flags(std::ios::hex);

	for (const byte& i : obj.dataset)
	{
		os.width(2);
		os << +i;
	}
	return os;
}


std::istream& operator>>(std::istream& is, block& obj)
{
	std::string buf;
	std::getline(is, buf);
	obj.construct(&buf);
	return is;
}

std::string& operator>>(const std::string& s, block& rhs)
{
	rhs.construct(&s);
	return const_cast<std::string&>(s);
}
