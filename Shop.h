#pragma once
#include"Items.h"
#include <string>
#include<vector>
#include"Entrances.h"
using namespace std;

//Ïåðâûé ýòàï - ôîðìèðóåì êëàññ Ìàãàçèí
class Shop
{
	vector<Item>goods; //Ñïèñîê òîâàðîâ, íåîáõîäèìî ñîçäàòü êëàññ Item 
	vector<Entrance> entrances; //Ñïèñîê ïîñåùåíèé
public:
	Shop();
	void setup_goods(string name, float price, int quantity, int ID = 0); //Ôóíêöèÿ äëÿ ðó÷íîé çàãðóçêè ÷åðåç ïåðåäà÷ó âñåõ àòðèáóòîâ òîâàðà â ôóíöèþ
	void setup_goods(string file_path); //Ôóíêöèÿ äëÿ àâòîìàòèçèðîâàííîé çàãðóçêè òîâàðîâ ÷åðåç ôàéë
	void setup_goods(Item item);//Ôóíêöèÿ äëÿ ðó÷íîé çàãðóçêè ÷åðåç ïåðåäà÷ó âñåõ àòðèáóòîâ
	void get_item(int quantity, string item_name); // Â ðàçðàáîòêå
	void get_summary();  // Â ðàçðàáîòêå
	void EnterClient(string clientName); // Ôóíêöèÿ ïðèåìà êëèåíòà
	void saveGoods(string file_path);

};