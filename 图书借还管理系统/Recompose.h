#pragma once
#include"Infomation.h"
class Recompose:public Infomation
{
public:
	struct Info
	{
		char Name[21], Number[51];
		int amount;
	};
	void choice();
};

