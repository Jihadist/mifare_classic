#pragma once
#include "block.h"
class trailer: block
{
public:
	std::string get_key(const byte type)
	{
		switch (type)
		{
			case 'A'|'a': return subblock(0);
			case 'B' | 'b': return subblock(10);
			default: {
				std::cerr << "Provide type of key" << std::endl;
				return NULL; }
		}
	}

private:

};