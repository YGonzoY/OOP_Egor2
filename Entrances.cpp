#include "Entrances.h"

Entrance::Entrance(string _clientName) : clientName{ _clientName }
{
	items = vector<Item>();
	works = vector<Work>();

}

void Entrance::add_work(Work work)
{
	works.push_back(work);
}

void Entrance::add_item(Item item)
{
	items.push_back(item);
}
