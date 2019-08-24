#include "trailer.h"

std::string trailer::get_key(const byte type)
{
	switch (type)
	{
	case 'A' | 'a': return subblock(0);
	case 'B' | 'b': return subblock(10);
	default:
		{
			std::cerr << "Provide type of key" << std::endl;
			return NULL;
		}
	}
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
