#pragma once
#include <string>
using namespace std;
class Human
{
	string first_name;
	string last_name;
	string middle_name;
	int age;
public:
	Human();
	Human(string _last_name, string _middle_name, string _first_name, int _age);
	virtual  void sayYourName(string something);
	void sayYourName();
	string fName();
	string mName();
	string lName();
	int Age();

};
