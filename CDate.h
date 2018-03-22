#pragma once
#include "stdafx.h"

class CDate
{
public:
	void setDate(void);
	void backAll(int, int);
	void backline(int, int);
	int  firstDay(int, int);
	bool second(int);
	int  dayOfMonth(int, int);
	void show(void);
private:
	int year;
	int month;
	int day;
	int line ;
	int lineTemp ;
	int lineGoto ;
};

