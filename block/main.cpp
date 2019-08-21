// block.cpp: определяет точку входа для приложения.
//
#include "../infint/InfInt.h"
#include "block.h"
#include "trailer.h"
#include <iostream>
#include <vector>

using namespace std;

int main()
{

	cout << "Hello CMake."<< endl;
	block b;
	cin >>b;
	cout << b;
	trailer t;

	return 0;
}


