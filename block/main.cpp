// block.cpp: определяет точку входа для приложения.
//

#include "block.h"
#include "trailer.h"
#include "card.h"
#include <iostream>
#include <fstream>

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
	std::string buf;
	std::ifstream file; ;
	card c(1);
	//cin >> c;
	file.open("D:/linux/RFID/Самара/MCT Dumps/9643 90630 33039 91914");
	//file.open(s"fi");
	if (file.is_open())
		file >> c;
	//else
	//	throw std::runtime_error("file couldn't open");
	cout << c;
	//std::getline(file, buf);
	//std::cout << buf;
	//cout << c.debug()->at(0);

}

int main()
{
	
	card_test();
	//cout << c.debug()->capacity();
	
	cout << "Hello CMake."<< endl;

	return 0;
}


