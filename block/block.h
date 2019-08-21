// block.h : включаемый файл для стандартных системных включаемых файлов
// или включаемые файлы для конкретного проекта.

#pragma once
#include <algorithm>
#include <iosfwd>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>

typedef uint8_t byte;
class block
{
	
public:
	explicit block(std::string* s)
	{
		if (check(s))
			construct(s);
	}

	block() :byteset(16){	}
	friend std::ostream& operator<<(std::ostream& os, const block& obj);
	friend std::istream& operator>>(std::istream& is, block& obj);
	static byte * extract(block& obj) { return obj.byteset.data(); }
	block change(const byte pos, byte value)
	{
		byteset.at(pos) = value;
		return *this;
	}
	byte get(const byte pos) { return byteset.at(pos); }
	
private:
	std::vector<byte> byteset;
	void construct(std::string* s)
	{
		if (check(s))
			for (byte i = 0; i != 16; ++i)
				byteset.at(i) = std::stoi(s->substr(i * 2, 2), nullptr, 16);
	}

	static int check(std::string* s)
	{
		if (s->size() != 32)
		{
			std::cerr << "Uncorrected block length";
			return 2;
		}
		return 1;
	}

	std::shared_ptr<std::stringstream> subblock(const byte pos, const byte len)
	{
		std::shared_ptr<std::stringstream> stream;
		stream->fill('0');
		stream->flags(std::ios::hex);
		std::for_each(byteset.begin() + pos, byteset.end() + pos + len, [&stream](const byte n)
			{ stream->width(2); *stream << +n; });
		return stream;
	}
};

inline
std::ostream& operator<<(std::ostream& os, const block& obj)
{
	os.fill('0');
	os.flags(std::ios::hex);
	
	for (const byte &i : obj.byteset)
	{
		os.width(2);
		os <<+i;
	}
	return os;
}

inline 
std::istream& operator>>(std::istream& is, block& obj)
{
	std::string buf;
	std::getline(is, buf);
	obj.construct(&buf);
	return is;
}
