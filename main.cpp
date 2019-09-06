// block.cpp: определяет точку входа для приложения.
//


#include <iostream>
#include <fstream>

#include "include/block.h"
#include "include/trailer.h"
#include "include/card.h"

using namespace std;

void block_test(){
	block b;
	cin >> b;
	cout << b<<endl;
	trailer t;
	auto buf = reinterpret_cast<trailer*>(&b)->get_key('b');
	cout << buf<<endl;
	reinterpret_cast<trailer*>(&b)->set_key("B5C8B4C2345E", 'a');
	reinterpret_cast<trailer*>(&b)->set_key("B5C8B4C5345E", 'b');
	cout << b << endl;
	}

void card_test()
{
	//cout << endl;
	std::string buf;
	std::ifstream file; ;
	card c(1);
	file.open("D:/linux/RFID/Самара/MCT Dumps/9643 90630 33039 91914");
	if (file.is_open())
		file >> c;
	else
		throw std::runtime_error("file couldn't open");
	cout << c;
	cout << endl;
}

int main()
{
	
	card_test();
	
	cout << "Hello CMake."<< endl;

	return 0;
}


