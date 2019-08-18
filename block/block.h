// block.h : включаемый файл для стандартных системных включаемых файлов
// или включаемые файлы для конкретного проекта.

#pragma once

typedef uint8_t byte;
class block
{
	
public:
	explicit block(std::string* s)
	{
		check(s);
		for (auto i=0;i!=16;i=i+2)
		{
			byteset.at(i) = std::stoi(s->substr(i, 2), 0, 16);
		}
	}

	block() :byteset(16){	}
	friend std::ostream& operator<<(std::ostream& os, const block& obj);
	friend std::istream& operator>>(std::istream& is, block& obj);
	static auto extract(block& obj)
	{
		return obj.byteset.data();
	}
private:
	std::vector<byte> byteset;
	void construct(std::string *s){
		check(s);
		for (byte i = 0; i != 16; ++i)
		{
			byteset.at(i) = std::stoi(s->substr(i*byte(2), 2), nullptr, 16);
		}
	}
	void check(std::string *s)
	{
		if (s->size() != 32)
			throw std::runtime_error("Uncorrected block length");
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
