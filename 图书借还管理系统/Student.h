#pragma once

#include<string>
using namespace std;
class Student
{
private:
	int type;
	string name, id;
public:
	Student(int t=1) { type = t; }	//构造函数，默认学生为本科生
	void Register();
	string getname() { return name; }	//返回学生姓名
	string getid() { return id; }		//返回学生学号
	int gettype() { return type; }		//返回学生类型
	void setwhite();					//设置字体为白色
	void setred();						//设置字体为红色
	void setcyan();						//设置字体为青色
	void setblue();						//设置字体为蓝色
};

