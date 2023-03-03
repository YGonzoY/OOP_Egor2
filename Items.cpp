#include "Items.h"
#include<iostream>
#include<fstream>
#include "ShopService.h"
#include <regex>

Item::Item(string _name, float _price, int _quantity, int _ID) :name{ _name }
, price{ _price }, quantity{ _quantity }, ID{ _ID }
{
	if (_ID == 0)
	{
		int tmp_id = getItemIDs(ShopService::configPath["IDs"]);
		if (tmp_id != 0)
		{
			IDs = tmp_id;
		}
		GenIDs();
		ID = IDs;
	}

	setItemIDs(ShopService::configPath["IDs"]);

}

void Item::add_quantity(int _value)
{
	quantity += _value;
}

void Item::delete_quantity(int _value)
{
	if (quantity >= _value)
		quantity -= _value;
	else
		std::cout << "Error\n";
}

string Item::Name()
{
	return name;
}

int& Item::Quantity()
{
	return quantity;
}

int Item::getItemIDs(string path)
{
	int result = 0;
	string text;
	fstream file(ShopService::configPath["IDs"]);
	while (!file.eof())
	{
		string line;
		getline(file, line);
		text += line + "\n";
	}
	regex regEx("(LastGoodsID)\\s([0-9]+)");
	vector<string> m_vecFields{ sregex_token_iterator(text.begin(), text.end(), regEx, 2), sregex_token_iterator() };
	if (m_vecFields[0] != "")
		result = strtol(m_vecFields[0].data(), NULL, 10);
	file.close();
	return result;
}

void Item::setItemIDs(string path)
{
	string text;
	fstream in(path);
	while (!in.eof())
	{
		string line;
		getline(in, line);
		text += line + "\n";
	}
	in.close();
	fstream out(ShopService::configPath["IDs"], ios::out);
	regex regEx("(LastGoodsID)\\s[0-9]+");
	text = regex_replace(text, regEx, "LastGoodsID " + to_string(ID));
	out << text.substr(0, text.size() - 1);
	out.close();
}

float& Item::Price()
{
	return price;
}

int Item::GetIDs()
{
	return IDs;
}

void Item::GenIDs()
{
	IDs++;
}
int Item::IDs = 0;