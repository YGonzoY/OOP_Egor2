#include "Works.h"

void Work::genIDs()
{
}

Work::Work(int _ID, string _name, float _price_of_hour, float _worktime) :ID{ _ID }, name{ _name },
price_of_hour{ _price_of_hour }, worktime{ _worktime }
{

}