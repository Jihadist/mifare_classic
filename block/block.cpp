// block.cpp: определяет точку входа для приложения.
//
#include "../infint/InfInt.h"
#include "block.h"

using namespace std;

struct foo
{
	friend void store(std::string* s);
	int a, b,c,d;
};

void store(std::string* s,foo * bar)
{
	sscanf_s(s->substr(0, 8).c_str(), "%x", &bar->a);
	sscanf_s(s->substr(8, 8).c_str(), "%x", &bar->b);
	sscanf_s(s->substr(16, 8).c_str(), "%x", &bar->c);
	sscanf_s(s->substr(24, 8).c_str(), "%x", &bar->d);

	std::cout << std::hex <<bar->a<<bar->b<<bar->c<<bar->d<< std::endl;

}


int main()
{

	cout << "Hello CMake."<< endl;
	block b;
	cin >>hex>> b;
	//cout << "number is" << b;
	std::string buffer = block::extract(b);
	cout << buffer;

	return 0;
}


