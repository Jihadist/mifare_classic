#pragma once
#include "block.h"
class trailer: block
{
public:
	std::string get_key(const byte type);
	std::string get_acs();
	byte get_gpb();

	trailer* set_acs(const std::string);
	trailer* set_gpb(const std::string);
	trailer* set_gpb(const byte&&);
	bool set_key(const std::string key, const byte type);

private:

};