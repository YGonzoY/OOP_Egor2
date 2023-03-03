#pragma once
#include"Shop.h"
#include"Service.h"
#include"Employers.h"
#include <map>

enum typeVisit
{
	toBuy = 0,
	toRepair = 1
};
class ShopService :public Shop, public Service
{
	vector<Employer> employers;
	Shop shop;
	Service service;
	string nameOrganization;

public:
	static map<string, string> configPath;
	void create_employers(string path_file, string _nameOrganization);
	void getlastIDEmployers(string path_file);
	ShopService(string _nameOrganization);
	void visit_client(int type_of_visit, string clientName);
	string getName() { return nameOrganization; }
	void addNewEmployer(string _lName,
		string _fName, string _mName, int _age
		, int _departament, int _position, bool _status = true);
	friend string* getPathConfig(ShopService obj);
	void get_out_employers();
	void saveEmployers();
	void saveEmployersIDs();
	int getEmployersIDs();
	~ShopService();
};