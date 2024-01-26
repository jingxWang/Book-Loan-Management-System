#include "Recompose.h"
#include "Infomation.h"
#include<iostream>
#include<fstream>
#include<iomanip>
#include<stdlib.h>
#include<string>
#include<string.h>
using namespace std;

void Recompose::choice()
{
	int choice;
	cin >> choice;
	while (choice)
	{
		switch (choice)
		{
		case 1:
			createFile();
			cout << "\t\t\t\t\t****             录入成功！          ****\n\n";
			break;
		case 2:
			borrow();
			break;
		case 3:
			back();
			break;
		case 4:
			showborrow();
			break;
		case 5:
			showFile();
			break;
		case 6:
			Sort();
			break;
		}
		set();
		cin >> choice;
	}
	cout << "\n\t\t\t\t\t****    感谢您的使用，欢迎下次体验！ ****\n";
}