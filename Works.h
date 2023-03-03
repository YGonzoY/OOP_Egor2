#pragma once
#include <string>
using namespace std;
class Work
{
	float price_of_hour;
	string name;
	float worktime;
	int ID;
	static int IDs;
	static void genIDs();
	friend void SetIDs(int _ID);
public:
	Work(int ID, string name, float _price_of_hour, float worktime = 1.0f);

};