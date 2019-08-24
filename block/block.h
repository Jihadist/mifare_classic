// block.h : включаемый файл для стандартных системных включаемых файлов
// или включаемые файлы для конкретного проекта.

#pragma once
#include <algorithm>
#include <iosfwd>
#include <string>
#include <iostream>
#include <sstream>
#include <array>
#include <vector>

typedef uint8_t byte;
typedef std::array<byte,16> byteset;
class block
{
	
public:
	explicit block(std::string* s);

	explicit block(const char* c);
	block() = default;

	friend std::ostream& operator<<(std::ostream& os, const block& obj);
	friend std::istream& operator>>(std::istream& is, block& obj);
	static byte * extract(block& obj) { return obj.dataset.data(); }
	block change(const byte pos, byte value);
	byte get(const byte pos) { return dataset.at(pos); }
protected:
	static int check(std::string* s);

	std::string subblock(const byte pos, const byte len = 6);
	static std::vector<byte> str_to_vec(const std::string* s);

	byteset dataset;
private:
	
	void construct(std::string* s);

};

inline
std::ostream& operator<<(std::ostream& os, const block& obj)
{
	os.fill('0');
	os.flags(std::ios::hex);
	
	for (const byte &i : obj.dataset)
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
