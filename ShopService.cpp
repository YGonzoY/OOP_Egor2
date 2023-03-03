#include "ShopService.h"
#include<iostream>
#include<fstream>
#include<string>
#include"windows.h"
#include"Employers.h"
#include <regex>
#include <map>

void ShopService::create_employers(string path_file, string _nameOrganization)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string line;
	char* fName = new char[20];
	char* mName = new char[20];
	char* lName = new char[20];
	int age;
	int position;
	int department;
	int status;
	int ID;

	fstream file(path_file, std::ios_base::in);
	while (!file.eof())
	{

		getline(file, line);
		if (line == "")
			continue;
		sscanf_s(line.data(), "%d %s %s %s %d %d %d %d", &ID, lName, 10, fName,
			10, mName, 20, &age, &position, &department, &status);
		employers.push_back(Employer(ID, lName, fName, mName, age, position, department, (bool)status));

	}
	file.close();

}

void ShopService::getlastIDEmployers(string path_file)
{
	fstream file(path_file, ios_base::in);
	string line;
	char name[20];
	int ID;
	while (!file.eof())
	{
		getline(file, line);
		auto tmp = line.find("LastEmployerID");
		if (line.find("LastEmployerID") == 0)
		{
			sscanf_s(line.data(), "%s %d", name, 20, &ID);
			Employer::IDs = ID;
		}
	}
}
std::map<string, string> ShopService::configPath{ {"Employers", "Employers.txt"},{"Goods", "Goods.txt"},{"IDs", "LastID.txt"} };
ShopService::ShopService(string _nameOrganization)
{
	shop = Shop();
	service = Service();
	nameOrganization = _nameOrganization;
}

void ShopService::visit_client(int type_of_visit, string clientName)
{
	if (type_of_visit)
	{
		service.EnterClient(clientName);
		for (auto man : employers)
		{
			man.sayYourName(nameOrganization);
		}
	}
	else
	{
		shop.EnterClient(clientName);
		for (auto man : employers)
		{
			man.sayYourName(nameOrganization);
		}

	}



}

void ShopService::addNewEmployer(string _lName, string _fName, string _mName,
	int _age, int _departament, int _position, bool _status)
{
	employers.push_back(Employer(0, _lName,
		_fName, _mName, _age, _departament
		, _position, _status));
}

void ShopService::get_out_employers()
{
}

void ShopService::saveEmployers()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	fstream file("Employers.txt", ios_base::out);
	char* tmp = new char[100];
	for (auto emp : employers)
	{

		sprintf_s(tmp, 100, "%d %s %s %s %d %d %d %d\n"
			, emp.ID, emp.lName().data(), emp.fName().data(), emp.mName().data(), emp.Age(), emp.department, emp.position, emp.status);
		file << tmp;
	}
	file.close();
}

void ShopService::saveEmployersIDs()
{
	string text;
	fstream in(ShopService::configPath["IDs"]);
	while (!in.eof())
	{
		string line;
		getline(in, line);
		text += line + "\n";
	}
	in.close();
	fstream out(ShopService::configPath["IDs"], ios::out);
	regex regEx("(LastEmployerID)\\s[0-9]+");
	text = regex_replace(text, regEx, "LastEmployerID " + to_string(Employer::IDs));
	out << text;
	out.close();
}

int ShopService::getEmployersIDs()
{
	return 0;
}


ShopService::~ShopService()
{
	saveEmployers();
	saveGoods(configPath["Goods"]);
}

string* getPathConfig(ShopService obj)
{
	return nullptr;
}