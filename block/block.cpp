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
			dataset.at(i) = std::stoi(s->substr(i * 2, 2), nullptr, 16);
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

std::string block::subblock(const byte pos, const byte len)
{
	std::shared_ptr<std::stringstream> stream;
	stream->fill('0');
	stream->flags(std::ios::hex);
	std::for_each(dataset.begin() + pos, dataset.end() + pos + len, [&stream](const byte n)
	{
		stream->width(2);
		*stream << +n;
	});
	return stream->str();
}
