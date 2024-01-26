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
	cout << "\n\t\t\t\t\t****         ��ѡ����Ҫ�Ĳ���        ****" << endl;
	cout << "\t\t\t\t\t****                                 ****" << endl;
	cout << "\t\t\t\t\t****  1.¼���鼮��Ϣ  2.�����鼮     ****" << endl;
	cout << "\t\t\t\t\t****  3.�黹�鼮      4.����ѽ��鼮 ****" << endl;
	cout << "\t\t\t\t\t****  5.��ѯ�鼮��Ϣ  6.���鼮����   ****" << endl;
	cout << "\t\t\t\t\t****               0.�˳�            ****" << endl;
}
void Infomation::setInfomatiom_Data()
{
	cout << "\n\n\t\t\t\t\t*****************************************" << endl;
	cout << "\n\t\t\t\t\t****           ͼ�����ϵͳ          ****" << endl;
	cout << "\t\t\t\t\t****                                 ****" << endl;
	set();
	cout << "\t\t\t\t\t****                                 ****" << endl;
	cout << "\n\t\t\t\t\t*****************************************" << endl;
}
//�����createFile������¼�����ļ�
void Infomation::createFile()
{
	fstream file("D:\\c++\\������\\Info.txt", ios::in | ios::out | ios::binary);
	if (file.fail())
	{
		cout << "���ļ�Info.txt����\n";
		exit(0);
	}
	Info person;
	file.seekg(0, ios::beg);
	for (int count = 0; count < 5; count++)
	{
		cout << "д��¼��" << count << endl;
		cout << "�������������Ϣ��\n";
		cin.ignore();
		cout << "������";

		cin >> person.Name;
		cin.ignore();
		//cin.getline(person.Name,21);
		cout << "�鼮��ţ�";
		cin.getline(person.Number, 21);
		cout << "�������";
		cin >> person.amount;
		file.write((char*)&person, sizeof(person));
	}
	file.flush();
	file.close();
}

//showFile����������ʾ�ļ�������
void Infomation::showFile()
{
	fstream file("D:\\c++\\������\\Info.txt", ios::in | ios::out | ios::binary);
	if (file.fail())
	{
		cout << "���ļ�Info.txt����\n";
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
			cout << "������" << person.Name;
			cout << setw(20) << "�鼮���:" << person.Number;
			cout << "\t�������" << person.amount << endl;
		}
		else break;
	}
	file.close();
}
 //borrow����ʵ�ֽ��Ĺ���
 void Infomation::borrow()
 {
	 fstream file("D:\\c++\\������\\Info.txt", ios::in | ios::out | ios::binary);
	 if (file.fail())
	 {
		 cout << "���ļ�Info.txt����\n";
		 exit(0);
	 }
	 Info person;
	 long long recNum;
	 file.clear();
	 cout << "������ĵڼ����飿";
	 cin >> recNum;
	 recNum--;
	 cin.ignore();
	 file.seekg(recNum * sizeof(person), ios::beg);
	 file.read((char*)&person, sizeof(person));		//����ԭ��������
	 //��ʾԭ������
	 cout << "������" << person.Name;
	 cout << setw(20) << "�鼮���:" << person.Number;
	 cout << "\t�������" << person.amount << endl;
	 cout << "��������Ҫ���ĵ�������\n";
	 int x;
	 cin >> x;
	 person.amount -= x;
	 cin.ignore();
	 file.seekg(recNum * sizeof(person), ios::beg);
	 file.write((char*)&person, sizeof(person));
	 file.flush();
	 file.close();
 }
 //back����ʵ�ֹ黹�鼮�޸�
 void Infomation::back()
 {
	 fstream file("D:\\c++\\������\\Info.txt", ios::in | ios::out | ios::binary);
	 if (file.fail())
	 {
		 cout << "���ļ�Info.txt����\n";
		 exit(0);
	 }
	 Info person;
	 long long recNum;
	 file.clear();
	 cout << "����黹�ڼ����飿";
	 cin >> recNum;
	 recNum--;
	 cin.ignore();
	 file.seekg(recNum * sizeof(person), ios::beg);
	 file.read((char*)&person, sizeof(person));		//����ԭ��������
	 //��ʾԭ������
	 cout << "������" << person.Name;
	 cout << setw(20) << "�鼮���:" << person.Number;
	 cout << "\t�������" << person.amount << endl;
	 cout << "��������Ҫ���ĵ�������\n";
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
	fstream file("D:\\c++\\������\\Info.txt", ios::in | ios::out | ios::binary);
	if (file.fail())
	{
		cout << "���ļ�Info.txt����\n";
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
				cout << "������" << person.Name;
				cout << setw(20) << "�鼮���:" << person.Number;
				cout << "\t����������" << 3-person.amount << endl;
			}
		}
		else break;
	}
	file.close();
}
//Sort����ʵ������
void Infomation::Sort()
{

	cout << "�����������鼮������������������Ա����˽���鼮���ܻ�ӭ��\n";
	fstream file("D:\\c++\\������\\Info.txt", ios::in | ios::out | ios::binary);
	if (file.fail())
	{
		cout << "���ļ�Info.txt����\n";
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
			cout << "������" << person[count].Name;
			cout << setw(20) << "�鼮���:" << person[count].Number;
			cout << "\t����������" << 3 - person[count].amount << endl;
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
	cout << "\n����ɹ���������ѡ��5���в鿴��";
}