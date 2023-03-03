#include "Human.h"
#include<iostream>

Human::Human() :first_name{}, last_name{}, middle_name{}, age{}// áàçîâûé êëàññ ÷åëîâåê
{
}

Human::Human(string _last_name, string _first_name, string _middle_name, int _age) : //Êîíñóòðóòîð ÷åëîâåêà
	last_name{ _last_name }, middle_name{ _middle_name }, first_name{ _first_name },
	age{ _age }
{
}

void Human::sayYourName(string something)
{
	std::cout << "Ìåíÿ çîâóò " << last_name << " " << first_name << "\n";

}

void Human::sayYourName()
{
	std::cout << "Ìåíÿ çîâóò " << last_name << " " << first_name << "\n";
}

string Human::fName()
{
	return first_name;
}

string Human::mName()
{
	return middle_name;
}

string Human::lName()
{
	return last_name;
}

int Human::Age()
{
	return age;
}