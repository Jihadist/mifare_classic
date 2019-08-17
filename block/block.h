// block.h : включаемый файл для стандартных системных включаемых файлов
// или включаемые файлы для конкретного проекта.

#pragma once

#include <iostream>
class block
{
public:
	block(std::string *s):a_(),b_(),c_(),d_()
	{
		construct(s);
	}
	block() = default;
	friend void read(std::ostream &os);
	friend void read(std::string& str);
	friend void write(std::istream& s);
	friend void write(std::string& str);
	friend std::ostream& operator<<(std::ostream& os, const block& obj);
	friend std::istream& operator>>(std::istream& is, block& obj);
	static std::string extract(block& obj)
	{
		std::stringstream ss;
		std::string str;
		ss << obj;
		ss >> str;
		return str;
	}
private:
	int a_, b_, c_, d_;
	void construct(std::string *s){
		sscanf_s(s->substr(0, 8).c_str(), "%x", &a_);
		sscanf_s(s->substr(8, 8).c_str(), "%x", &b_);
		sscanf_s(s->substr(16, 8).c_str(), "%x", &c_);
		sscanf_s(s->substr(24, 8).c_str(), "%x", &d_);
	}
};

inline
std::ostream& operator<<(std::ostream& os, const block& obj)
{
	os << std::setbase(16)<< obj.a_<<obj.b_<<obj.c_<<obj.d_;
	return os;
}

inline 
std::istream& operator>>(std::istream& is, block& obj)
{
	std::string str;
	is >> str;
	obj.construct(&str);
	return is;
}

// TODO: установите здесь ссылки на дополнительные заголовки, требующиеся для программы.
