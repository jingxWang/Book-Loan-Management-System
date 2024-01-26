#include<iostream>
#include "Infomation.h"
#include<fstream>
#include<iomanip>
#include<stdlib.h>
#include<string>
#include<string.h>
using namespace std;
void Infomation::set()
{
	cout << "\n\t\t\t\t\t****         请选择想要的操作        ****" << endl;
	cout << "\t\t\t\t\t****                                 ****" << endl;
	cout << "\t\t\t\t\t****  1.录入书籍信息  2.借阅书籍     ****" << endl;
	cout << "\t\t\t\t\t****  3.归还书籍      4.浏览已借书籍 ****" << endl;
	cout << "\t\t\t\t\t****  5.查询书籍信息  6.将书籍排序   ****" << endl;
	cout << "\t\t\t\t\t****               0.退出            ****" << endl;
}
void Infomation::setInfomatiom_Data()
{
	cout << "\n\n\t\t\t\t\t*****************************************" << endl;
	cout << "\n\t\t\t\t\t****           图书管理系统          ****" << endl;
	cout << "\t\t\t\t\t****                                 ****" << endl;
	set();
	cout << "\t\t\t\t\t****                                 ****" << endl;
	cout << "\n\t\t\t\t\t*****************************************" << endl;
}
//下面的createFile函数记录设置文件
void Infomation::createFile()
{
	fstream file("D:\\c++\\王景萱\\Info.txt", ios::in | ios::out | ios::binary);
	if (file.fail())
	{
		cout << "打开文件Info.txt出错！\n";
		exit(0);
	}
	Info person;
	file.seekg(0, ios::beg);
	for (int count = 0; count < 5; count++)
	{
		cout << "写记录：" << count << endl;
		cout << "请输入下面的信息：\n";
		cin.ignore();
		cout << "书名：";

		cin >> person.Name;
		cin.ignore();
		//cin.getline(person.Name,21);
		cout << "书籍编号：";
		cin.getline(person.Number, 21);
		cout << "库存量：";
		cin >> person.amount;
		file.write((char*)&person, sizeof(person));
	}
	file.flush();
	file.close();
}

//showFile函数可以显示文件的内容
void Infomation::showFile()
{
	fstream file("D:\\c++\\王景萱\\Info.txt", ios::in | ios::out | ios::binary);
	if (file.fail())
	{
		cout << "打开文件Info.txt出错！\n";
		exit(0);
	}
	Info person;
	file.clear();
	file.seekg(0L, ios::beg);
	while (!file.eof())
	{
		if (file.read((char*)&person, sizeof(person)))
		{
			if (file.fail())break;
			cout << "书名：" << person.Name;
			cout << setw(20) << "书籍编号:" << person.Number;
			cout << "\t库存量：" << person.amount << endl;
		}
		else break;
	}
	file.close();
}
 //borrow函数实现借阅功能
 void Infomation::borrow()
 {
	 fstream file("D:\\c++\\王景萱\\Info.txt", ios::in | ios::out | ios::binary);
	 if (file.fail())
	 {
		 cout << "打开文件Info.txt出错！\n";
		 exit(0);
	 }
	 Info person;
	 long long recNum;
	 file.clear();
	 cout << "你想借阅第几本书？";
	 cin >> recNum;
	 recNum--;
	 cin.ignore();
	 file.seekg(recNum * sizeof(person), ios::beg);
	 file.read((char*)&person, sizeof(person));		//读出原来的数据
	 //显示原来数据
	 cout << "书名：" << person.Name;
	 cout << setw(20) << "书籍编号:" << person.Number;
	 cout << "\t库存量：" << person.amount << endl;
	 cout << "请输入想要借阅的数量：\n";
	 int x;
	 cin >> x;
	 person.amount -= x;
	 cin.ignore();
	 file.seekg(recNum * sizeof(person), ios::beg);
	 file.write((char*)&person, sizeof(person));
	 file.flush();
	 file.close();
 }
 //back函数实现归还书籍修改
 void Infomation::back()
 {
	 fstream file("D:\\c++\\王景萱\\Info.txt", ios::in | ios::out | ios::binary);
	 if (file.fail())
	 {
		 cout << "打开文件Info.txt出错！\n";
		 exit(0);
	 }
	 Info person;
	 long long recNum;
	 file.clear();
	 cout << "你想归还第几本书？";
	 cin >> recNum;
	 recNum--;
	 cin.ignore();
	 file.seekg(recNum * sizeof(person), ios::beg);
	 file.read((char*)&person, sizeof(person));		//读出原来的数据
	 //显示原来数据
	 cout << "书名：" << person.Name;
	 cout << setw(20) << "书籍编号:" << person.Number;
	 cout << "\t库存量：" << person.amount << endl;
	 cout << "请输入想要借阅的数量：\n";
	 int x;
	 cin >> x;
	 person.amount += x;
	 cin.ignore();
	 file.seekg(recNum * sizeof(person), ios::beg);
	 file.write((char*)&person, sizeof(person));
	 file.flush();
	 file.close();
 }
void Infomation::showborrow()
{
	fstream file("D:\\c++\\王景萱\\Info.txt", ios::in | ios::out | ios::binary);
	if (file.fail())
	{
		cout << "打开文件Info.txt出错！\n";
		exit(0);
	}
	Info person;
	file.clear();
	file.seekg(0L, ios::beg);
	while (!file.eof())
	{
		if (file.read((char*)&person, sizeof(person)))
		{
			if (file.fail())break;
			if (person.amount<3)
			{
				cout << "书名：" << person.Name;
				cout << setw(20) << "书籍编号:" << person.Number;
				cout << "\t借阅数量：" << 3-person.amount << endl;
			}
		}
		else break;
	}
	file.close();
}
//Sort函数实现排序
void Infomation::Sort()
{

	cout << "接下来按照书籍库存量进行升序排序，以便您了解各书籍的受欢迎度\n";
	fstream file("D:\\c++\\王景萱\\Info.txt", ios::in | ios::out | ios::binary);
	if (file.fail())
	{
		cout << "打开文件Info.txt出错！\n";
		exit(0);
	}
	Info person[100];
	int count = 0;
	file.clear();
	file.seekg(0L, ios::beg);
	while (!file.eof())
	{
		if (file.read((char*)&person[count], sizeof(person[count])))
		{
			if (file.fail())break;
			cout << "书名：" << person[count].Name;
			cout << setw(20) << "书籍编号:" << person[count].Number;
			cout << "\t借阅数量：" << 3 - person[count].amount << endl;
			count++;
		}
		else break;
	}
	cout << endl << count << endl;
	for (int i = 0; i < count-1 ; i++)
		for (int j = i + 1; j < count ; j++)
		{
			if (person[i].amount < person[j].amount)
			{
				char a[21], b[51];
				char* temp1 = a, * temp2 = b;
				int temp3;
				strcpy_s(temp1, strlen(person[i].Name) + 1, person[i].Name);
				strcpy_s(person[i].Name, strlen(person[j].Name) + 1, person[j].Name);
				strcpy_s(person[j].Name, strlen(temp1) + 1, temp1);
				strcpy_s(temp2, strlen(person[i].Number) + 1, person[i].Number);
				strcpy_s(person[i].Number, strlen(person[j].Number) + 1, person[j].Number);
				strcpy_s(person[j].Number, strlen(temp2) + 1, temp2);
				temp3 = person[i].amount;
				person[i].amount = person[j].amount;
				person[j].amount = temp3;
			}
		}
	file.seekg(0L, ios::beg);
	for (int i = 0; i < count; i++)
	{
		file.write((char*)&person[i], sizeof(person[i]));
	}
	file.close();
	cout << "\n排序成功，您可以选择5进行查看！";
}