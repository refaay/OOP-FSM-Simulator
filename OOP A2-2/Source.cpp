// Ahmed Refaay
// OOP
// Assignment 2

#include <iostream>
#include <fstream>
#include <string>
#include <exception>
#include <typeinfo>
#include <stdexcept>
#include <vector>

// Defined classes
#include "Machine.h"

int main(){
	std::cout << "Main start:\n";
	try{
		//std::cout << "FSM try start:\n";
		Machine ("fsmThree").execute();
		//std::cout << "FSM try end.\n";
	}
	catch(const string& e){
		//std::cout << "FSM catch start:\n";
		std::cerr << e << endl;
		//std::cout << "FSM catch end.\n";
	}
	system("pause");
	return 0;
}