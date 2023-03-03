#include "Sql.h"
#include <iostream>
#include <windows.h>
#include <oledb.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>
#include <conio.h>
#include <regex>
#include "AdoImport.h"
#include "Msado15.tlh.h"
using namespace std;
#import "C:\Program Files (x86)\Common Files\System\ado\msado15.dll" no_namespace rename("EOF", "EndOfFile")



wchar_t* char2wchar(const char* cchar)
{
	wchar_t* m_wchar;
	int len = MultiByteToWideChar(CP_ACP, 0, cchar, (int)strlen(cchar), NULL, 0);
	m_wchar = new wchar_t[len + 1];
	MultiByteToWideChar(CP_ACP, 0, cchar, (int)strlen(cchar), m_wchar, len);
	m_wchar[len] = '\0';
	return m_wchar;
}
void exec_IN(const char* cmd) {
	std::array<char, 128> buffer;
	std::string result;
	std::unique_ptr<FILE, decltype(&_pclose)> pipe(_popen(cmd, "r"), _pclose);
	if (!pipe) {
		throw std::runtime_error("popen() failed!");
	}
	while (fgets(buffer.data(), (int)buffer.size(), pipe.get()) != nullptr) {
		result += buffer.data();
	}
}

wchar_t* exec(const char* cmd) {
METKA:
	std::array<char, 128> buffer;
	std::string result;
	std::unique_ptr<FILE, decltype(&_pclose)> pipe(_popen(cmd, "r"), _pclose);
	if (!pipe) {
		throw std::runtime_error("popen() failed!");
	}
	while (fgets(buffer.data(), (int)buffer.size(), pipe.get()) != nullptr) {
		result += buffer.data();
	}

	regex regEx("(Instance pipe name:)\\s(\\S+)");
	vector<string> m_vecFields{ sregex_token_iterator(result.begin(), result.end(), regEx, 2), sregex_token_iterator() };
	regEx = regex("(Èìÿ êàíàëà ýêçåìïëÿðà:)\\s(\\S+)");
	if (m_vecFields.size() != 1)
		m_vecFields = { sregex_token_iterator(result.begin(), result.end(), regEx, 2), sregex_token_iterator() };
	if (m_vecFields.size() != 1)
	{
		exec_IN("SqlLocalDB.exe start");
		goto METKA;
	}
	wchar_t connection[255] = L"provider=SQLOLEDB; initial catalog=master; data source=";
	wcscat_s(connection, 255, char2wchar(m_vecFields[0].data()));
	wcscat_s(connection, 255, L"; Trusted_Connection=yes; ");
	return connection;
}

SQL::SQL()
{
	HRESULT T = CoInitialize(NULL);
	_ConnectionPtr pConn(__uuidof(Connection));
	_RecordsetPtr pRs(__uuidof(Recordset));
	//exec_IN("SqlLocalDB.exe start");
	//_bstr_t strCnn("Data Source=(localdb)\ProjectsV12;Initial Catalog=master;Integrated Security=True;Connect Timeout=30;Encrypt=False;TrustServerCertificate=False;");
	wchar_t* connection = exec("SqlLocalDB.exe i \"MSSQLLocalDB\"");
	pConn->Open(connection, L"", L"", 0);
	string sqlTest = "IF NOT EXISTS(SELECT * FROM sys.databases WHERE name = 'Test') BEGIN CREATE DATABASE Test END";
	pRs = pConn->Execute(sqlTest.data(), NULL, adCmdText);
	pRs.Release();
	sqlTest = "USE TEST;IF NOT EXISTS (select * from INFORMATION_SCHEMA.TABLES S where S.TABLE_CATALOG = 'TEST' and S.TABLE_NAME = 'TEST') BEGIN CREATE Table TEST(Id INT, name varchar(50)) END";
	pRs = pConn->Execute(sqlTest.data(), NULL, adCmdText);
	pRs.Release();
	sqlTest = "USE TEST;IF NOT EXISTS (select * from test) BEGIN INSERT INTO TEST(Id, name) values (1, 'Mate') INSERT INTO TEST(Id, name) values (2, 'House') END";
	pRs = pConn->Execute(sqlTest.data(), NULL, adCmdText);
	pRs.Release();
	sqlTest = "select * from test";
	pRs = pConn->Execute(sqlTest.data(), NULL, adCmdText);

	while (!pRs->EndOfFile)
	{
		printf((_bstr_t)pRs->GetCollect("Id"));
		printf("\t");
		printf((_bstr_t)pRs->GetCollect("Name"));
		printf("\n");
		pRs->MoveNext();
	}

	pRs.Release();
	pConn.Release();
	::CoUninitialize();
}