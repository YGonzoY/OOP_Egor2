#include<iostream>
#include"ShopService.h"
#include"windows.h"
#include"SQL.h"


using namespace std;

enum Activity
{
	ÄîáàâèòüÒîâàð = 1,
	ÓäàëèòüÒîâàð,
	ÄîáàâèòüÐàáîòó,
	ÓäàëèòüÐàáîòó,
	ÏðèíÿòüÊëèåíòàÌàãàçèíà,
	ÏðèíÿòüÊëèåíòàÑåðâèñà,
	Âûéòè = 0

};
string ActivityString[] = {
	"Âûéòè",
	"Äîáàâèòü òîâàð",
	"Óäàëèòü òîâàð",
	"Äîáàâèòü ðàáîòó",
	"Óäàëèòü ðàáîòó",
	"Ïðèíÿòü êëèåíòà ìàãàçèíà",
	"Ïðèíÿòü êëèåíòà ñåðâèñà"
};
string to_string(Activity e) {
	return ActivityString[(int)e];
}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	ShopService myJob("Dream");
	myJob.create_employers(ShopService::configPath["Employers"], "Dream");
	myJob.saveEmployers();
	int count = 0;
	printf("Âûáèðèòå äåéñòâèå:\n");
	for (auto item : ActivityString)
	{
		printf("%d. %s\n", count, item.data());
		count++;
	}
	myJob.setup_goods("Ïèðîæîê", 10, 5);
	//	myJob.addNewEmployer("Èâàíîâ","Èâàí", "Èâàíîâè÷", 30, 1,2,1);
	SQL sql;
	return 0;
}