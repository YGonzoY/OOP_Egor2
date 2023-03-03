#include "Service.h"

Service::Service()
{
	ourWorks = vector<Work>();
	repairItems = vector<Item>();
}

void Service::EnterClient(string clientName)
{
	Entrance tmp(clientName);
	//Ëîãèêà ðàáîòû ñ êëèåíòîì.
	entrances.push_back(tmp);
}