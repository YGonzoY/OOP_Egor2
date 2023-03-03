#pragma once
#include <string>
#include"Items.h"
#include"Works.h"
#include<vector>
class Entrance
{
	std::string clientName;
	vector<Work> works;
	vector<Item> items;
public:
	Entrance(string _clientName);
	void add_work(Work work);
	void add_item(Item item);


};