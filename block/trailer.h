#pragma once
#include "block.h"
class trailer: block
{
public:
	std::string get_key(const byte type)
	{
		switch (type)
		{
			case 'A'|'a': return "aa";
			case 'B' | 'b': return "bb";
			default: {
				std::cerr << "Provide type of key" << std::endl;
				return nullptr; }
		}
	}

private:

};