#pragma once

#include<string>
using namespace std;
class Student
{
private:
	int type;
	string name, id;
public:
	Student(int t=1) { type = t; }	//���캯����Ĭ��ѧ��Ϊ������
	void Register();
	string getname() { return name; }	//����ѧ������
	string getid() { return id; }		//����ѧ��ѧ��
	int gettype() { return type; }		//����ѧ������
	void setwhite();					//��������Ϊ��ɫ
	void setred();						//��������Ϊ��ɫ
	void setcyan();						//��������Ϊ��ɫ
	void setblue();						//��������Ϊ��ɫ
};

