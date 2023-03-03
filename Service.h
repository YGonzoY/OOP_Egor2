#pragma once
#include<vector>
#include"Items.h"
#include"Works.h"
#include"Entrances.h"

// Âòîðîé ýòàï. Ñîçäàíèå êëàññà Ñåðâèñ äëÿ ïðîäàæè ðåìîíòíûõ ðàáîò è äåòàëåé
class Service
{
	vector<Entrance> entrances; //Ñïèñêî ïîñåùåèé êëèåíòà
	vector<Item> repairItems; // Ñïèñîê äåòàëåé
	vector<Work> ourWorks; // Ñïèñîê ðàáîò
public:
	Service();// Êîíñòðóêòîð ïî óìîë÷àíèþ
	void EnterClient(string clientName);

};
