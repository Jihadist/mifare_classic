#pragma once
#include "block.h"
class trailer final: block
{
public:
	std::string get_key(byte type);
	std::string get_acs();
	std::string get_gpb();

	trailer* set_acs(const std::string *);
	trailer* set_gpb(const std::string *);
	trailer* set_gpb(byte);
	bool set_key(std::string key, byte type);

private:
	auto pos_key_a() { return this->begin(); }
	auto pos_key_b() { return this->begin()+10; }
	auto pos_gpb() { return this->begin()+9; }
	auto pos_acs() { return this->begin()+6; }

};