#pragma once
#include "block.h"
class trailer: block
{
public:
	std::string get_key(const byte type);

	bool set_key(const std::string key, const byte type);

private:

};