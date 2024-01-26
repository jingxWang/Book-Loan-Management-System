#include "Student.h"
#include<windows.h>
#include<iostream>
using namespace std;
void Student::setwhite()		//白色
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
		FOREGROUND_GREEN | FOREGROUND_BLUE);
}
void Student::setred()			//红色
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
}
void Student::setcyan()			//青色
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN |
		FOREGROUND_BLUE);
}
void Student::setblue()						//设置字体为蓝色
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);
}
void Student::Register()
{
	cout << "\n\t\t\t\t\t*****************************************" << endl;
	cout << "\t\t\t\t\t****       欢迎使用财务管理系统      ****" << endl;
	cout << "\t\t\t\t\t****         版权所有：王景萱        ****" << endl;
	cout << "\t\t\t\t\t****        1.请先登陆您的信息       ****" << endl;
	cout << "\t\t\t\t\t****            0.退出系统           ****" << endl;
	cout << "\t\t\t\t\t*****************************************" << endl;
	int choice;
	cin >> choice;
	if (choice)
	{
		setblue();
		cout << "\t\t\t\t\t***************下面开始登陆**************" << endl;
		setwhite();
		cout << "\n* 请输入您的姓名：\t";
		cin >> name;
		cin.ignore();
		cout << "* 请输入您的学号：\t";
		cin >> id;
		cin.ignore();
		cout << "* 请输入您的学籍类型（0.本科生|1.研究生）：\t";
		cin >> type;
		setred();
		cout << "\n恭喜 ";
		setblue();
		if (!gettype())cout << "本科生 ";
		else cout << "研究生 ";
		cout << getname();
		setred();
		cout << " 登陆成功！\t\t 注： ";
		setwhite();
		if (!gettype())cout << "学校规得您（本科生）共可借10本书籍\n ";
		else cout << "学校规定您（研究生）共可借15本书籍\n ";
		cout << "\n\t\t\t\t\t****         3秒后进入借阅系统       ****";
		
	}
	else cout << "\n欢迎下次使用图书借还管理系统\n";
	Sleep(3 * 1000);					//延迟函数：若要延迟T秒，把3改为T即可
}
