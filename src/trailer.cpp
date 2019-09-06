#include "../include/trailer.h"

std::string trailer::get_key(const byte type)
{
	if(isalpha(type))
		switch (type)
		{
		case 'A' | 'a': return subblock(0);
		case 'B' | 'b': return subblock(10);
		default:
			{
				std::cerr << "Provide correct type of key" << std::endl;
				return NULL;
			}
		}
	std::cerr << "Provided uncorrected key type" << std::endl;
	return NULL;
}

std::string trailer::get_acs()
{
	return subblock(6,3);
}

std::string trailer::get_gpb()
{
	return subblock(6,1);
}

trailer* trailer::set_acs(const std::string* s)
{	
	if(s->size()!=6)
	{
		std::cerr << "uncorrected acs length" << std::endl;
		return nullptr;
	}
	auto buf = str_to_vec(s);
	std::move(buf.begin(), buf.end(), this->pos_acs());
	return this;
}

trailer* trailer::set_gpb(const std::string* s)
{
	if (s->size()!=2)
	{
		std::cerr << "uncorrected gpb length" << std::endl;
			return nullptr;
	}
	auto buf = str_to_vec(s);
	std::move(buf.begin(), buf.end(), this->pos_gpb());
	return this;
}

trailer* trailer::set_gpb(const byte b)
{

	dataset.at(9) = b;
	return this;
}

bool trailer::set_key(const std::string key, const byte type)
{
	std::cerr << "enter func set_key" << std::endl;
	if (key.size() != 12)
		std::cerr << "uncorrected key length" << std::endl;
	switch (type)
	{
	case 'A' | 'a':
		{
			auto buf = str_to_vec(&key);
			if (!buf.empty())
				std::move(buf.begin(), buf.end(), dataset.begin());
			return true;
		}
	case 'B' | 'b':
		{
			auto buf = str_to_vec(&key);
			std::move_backward(buf.begin(), buf.end(), dataset.end());
			return true;
		}
	default: return false;
	}
}
