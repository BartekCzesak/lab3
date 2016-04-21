#pragma once
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <string>


using namespace std;

enum gender {man, woman};

class Slav
{
private:
	static void init();

	static std::vector <string> names;
	static int _counter;

	string _name;
	int _id;

public:
	Slav();

	static int counter() { return _counter; }
	
	string name() { return _name; }
	int id() { return _id; }

	string description();
	
	gender Sex();
};
