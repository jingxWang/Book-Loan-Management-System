#include "Student.h"
#include<windows.h>
#include<iostream>
using namespace std;
void Student::setwhite()		//��ɫ
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED |
		FOREGROUND_GREEN | FOREGROUND_BLUE);
}
void Student::setred()			//��ɫ
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
}
void Student::setcyan()			//��ɫ
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN |
		FOREGROUND_BLUE);
}
void Student::setblue()						//��������Ϊ��ɫ
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);
}
void Student::Register()
{
	cout << "\n\t\t\t\t\t*****************************************" << endl;
	cout << "\t\t\t\t\t****       ��ӭʹ�ò������ϵͳ      ****" << endl;
	cout << "\t\t\t\t\t****         ��Ȩ���У�������        ****" << endl;
	cout << "\t\t\t\t\t****        1.���ȵ�½������Ϣ       ****" << endl;
	cout << "\t\t\t\t\t****            0.�˳�ϵͳ           ****" << endl;
	cout << "\t\t\t\t\t*****************************************" << endl;
	int choice;
	cin >> choice;
	if (choice)
	{
		setblue();
		cout << "\t\t\t\t\t***************���濪ʼ��½**************" << endl;
		setwhite();
		cout << "\n* ����������������\t";
		cin >> name;
		cin.ignore();
		cout << "* ����������ѧ�ţ�\t";
		cin >> id;
		cin.ignore();
		cout << "* ����������ѧ�����ͣ�0.������|1.�о�������\t";
		cin >> type;
		setred();
		cout << "\n��ϲ ";
		setblue();
		if (!gettype())cout << "������ ";
		else cout << "�о��� ";
		cout << getname();
		setred();
		cout << " ��½�ɹ���\t\t ע�� ";
		setwhite();
		if (!gettype())cout << "ѧУ������������������ɽ�10���鼮\n ";
		else cout << "ѧУ�涨�����о��������ɽ�15���鼮\n ";
		cout << "\n\t\t\t\t\t****         3���������ϵͳ       ****";
		
	}
	else cout << "\n��ӭ�´�ʹ��ͼ��軹����ϵͳ\n";
	Sleep(3 * 1000);					//�ӳٺ�������Ҫ�ӳ�T�룬��3��ΪT����
}
