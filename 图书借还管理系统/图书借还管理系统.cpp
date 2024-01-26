// 图书借还管理系统.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。

#include <iostream>
#include<stdlib.h>
#include<fstream>
#include<iomanip>
#include"Recompose.h"
int count;
using namespace std;
int main()
{
    Recompose object;
    object.Register();
    system("cls");              //调用stdlib.h中的清屏函数
    object.setInfomatiom_Data();
    object.choice();
}
