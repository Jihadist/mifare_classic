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
	if (check(s))
		for (byte i = 0; i != 16; ++i)
			dataset.at(i) = std::stoi(s->substr(int(i) * 2, 2), nullptr, 16);
}

std::vector<byte> block::str_to_vec(const std::string* s) 
{
	// ������� ��� �������� ����� �������� ������ �� ������ ������ �������� �����
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
	// ������ ����� ��� �� �����
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
