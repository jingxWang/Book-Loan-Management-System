#pragma once
#include<string>
#include"Student.h"
using namespace std;
class Infomation:public Student
{
private:
	struct Info
	{
		char Name[21], Number[21];
		int amount;
	}aaa[20];
public:
	Infomation(int a = 3) { aaa[0].amount = a; }
	void setInfomatiom_Data();
	int getamount(int i) { return aaa[i].amount; }
	string getName(int i) { return aaa[i].Name; }
	string getNumber(int i) { return aaa[i].Number; }
	void set();
	void createFile();
	void showborrow();
	//void editFile();
	void borrow();
	void back();
	void showFile();
	void Sort();
};