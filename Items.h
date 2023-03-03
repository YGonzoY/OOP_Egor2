#pragma once
#include <string>
using namespace std;

// Ýòàï òðåòèé
class Item // Êëàññ äåòàëåé
{
	string name;
	float price;
	int quantity;
	int ID;
	static int IDs;
public:
	friend class Shop;
	Item(string _name, float _price, int _quantity, int _ID);
	void add_quantity(int _value);
	void delete_quantity(int _value);
	string Name();
	int& Quantity();
	int getItemIDs(string path);
	void setItemIDs(string path);
	float& Price();
	static int GetIDs();
	static void GenIDs();

};