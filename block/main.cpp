// block.cpp: определяет точку входа для приложения.
//

#include "block.h"
#include "trailer.h"
#include <iostream>

using namespace std;

void test(){
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

int main()
{

	cout << "Hello CMake."<< endl;
	test();
	return 0;
}


