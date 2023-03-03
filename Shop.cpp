#include <iostream>
#include "Shop.h"
#include "Items.h"
#include "Entrances.h"
#include <fstream>
#include <string>
#include "ShopService.h"
#include "windows.h"


Shop::Shop()
{
	goods = vector<Item>();
	setup_goods(ShopService::configPath["Goods"]); // Ïðè ñîçäàíèè îáúåêòà êëàññà Shop ïðèíèìàåì ñïèñîê òîâàðîâ äëÿ ïðîäàæè
}

void Shop::setup_goods(string name, float price, int quantity, int ID) // ïðèìèòèâíàÿ ôóíêöèÿ äëÿ äîáàâëåíèÿ îäíîé ïîçèöèè òîâàðà
{

	bool flag = false;
	for (auto& good : goods)
	{

		if (good.Name() == name && good.Price() == price)
		{
			good.add_quantity(quantity);
			flag = true;
			break;
		}
	}
	if (!flag)
		goods.push_back(Item(name, price, quantity, ID));

}

void Shop::setup_goods(string file_path)
{
	fstream file(file_path, std::ios_base::in); //Îòêðûâàåì ôàéë â ðåæèìå ÷òåíèÿ
	char* name = new char[50];//Ñîçäàåì ìàññèâ char äëÿ õðàíåíèÿ ñèìâîëüíûõ äàííûõ
	float price; // Ïåðåìåííàÿ äëÿ ñîõðàíåíèÿ íå öåëî÷èñëåííûõ äàííûõ
	int quantity; // Ïåðåìåííàÿ äëÿ öåëî÷èñëåííûõ äàííûõ. Èñõîäè, ÷òî òîâàðû áóäóò ïðîäààòüñÿ ïîøòó÷íî
	int ID; // Èäåíòèôèêàòîð òîâàðà
	string line; // Ïåðåìåííàÿ äëÿ õðàíåíèÿ ñ÷èòàííîé ñòðîêè
	while (!file.eof())  // Öèêë äëÿ ÷òåíèÿ ôàéëà äî åãî êîíöà
	{
		getline(file, line); // ñ÷èòûâàåì ñòðîêó èç ôàéëà file è çàèñûâàåì â ïåðåìåííóþ line
		if (line == "")
			continue;
		sscanf_s(line.data(), "%d %s %f %d", &ID, name, 20, &price, &quantity); // Ïàðñèì ñðîêó ïî òèïàì äàííûõ
		setup_goods(name, price, quantity, ID);
		/*bool flag = false;
		for (auto& good : goods)
		{
			if (good.Name() == name and good.Price() == price)
			{
				good.add_quantity(quantity);
				flag = false;
				break;
			}
		}
		if (!flag)
			goods.push_back(Item(name, price, quantity));*/
			// Èñïîëüçóåì àëãîðèòì áîëåå ïðèìèòèâîé ôóíêöèè ïîñëå òîãî, êàê ðàñïàðñèëè òåêñòîâûé ôàéë äî ïðîñòîûõ àðãóìåíòîâ
	}
	file.close(); // Çàêðûâàåì ôàéë ïîñëå ÷òåíèÿ
}

void Shop::setup_goods(Item item)
{
}

void Shop::get_item(int quantity, string item_name)
{
}

void Shop::get_summary()
{
	for (auto good : goods)
	{
		cout << "Name: " << good.Name()
			<< ", price: " << good.Price() << " , quantity: "
			<< good.Quantity() << "\n";
	}
}

void Shop::EnterClient(string clientName)
{

	Entrance tmp(clientName);
	//Ëîãèêà ðàáîòû ñ êëèåíòîì.
	entrances.push_back(tmp);
}

void Shop::saveGoods(string file_path)
{

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	fstream file(file_path, ios_base::out);
	char* tmp = new char[100];
	for (auto item : goods)
	{

		sprintf_s(tmp, 100, "%d %s %.2f %d\n"
			, item.ID, item.name.data(), item.price, item.quantity);
		file << tmp;
	}
	file.close();



}