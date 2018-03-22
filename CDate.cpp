#include "stdafx.h"
#include "CDate.h"


void CDate::setDate(void)
{
	cout << "Please input a year: ";
	cin >> year;
	month = line = lineTemp = lineGoto = 1;
	system("cls");
}
void CDate::backAll(int x, int y)
{

	COORD c;
	c.X = x - 1;
	c.Y = y - 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	line++;
}
void CDate::backline(int x, int y)
{
	COORD c;
	c.X = x - 1;
	c.Y = y - 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	lineTemp++;
}
int CDate::firstDay(int year, int month)
{
	int day = 1;

	if (month == 1 || month == 2)
	{
		month = (month == 1 ? 13 : 14);
		year = year - 1;
	}

	return  (day + 2 * month + 3 * (month + 1) / 5 + year + year / 4 - year / 100 + year / 400 + 1) % 7;
}

int CDate::dayOfMonth(int year, int month)
{
	if (month == 2)
	{
		if (second(year))
		{
			return 29;
		}
		return 28;
	}
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
	{
		return 31;
	}
	return 30;
}
bool CDate::second(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		return true;
	return false;
}
void CDate::show()
{
	for (int monthTemp = 1; monthTemp <= 6; monthTemp ++)
	{
		backAll(70, line);
		cout << "        " << year << "年" << month +1 << "月";
		backAll(70, line);
		cout << "MON TUE WED THU FRI SAT SUN ";
		backAll(70, line);
		for (int i = 1; i < firstDay(year, month + 1); i++)
		{
			cout << "    ";
		}

		for (int i = 1; i <= dayOfMonth(year, month + 1); i++)
		{
			cout << setw(3) << i << " ";
			if ((i + firstDay(year, month + 1) - 1) % 7 == 0)
			{
				backAll(70, line);
			}
		}

		backline(10, lineTemp);
		cout << "        " << year << "年" << month << "月";
		backline(10, lineTemp);
		cout << "MON TUE WED THU FRI SAT SUN ";
		backline(10, lineTemp);
		for (int i = 1; i < firstDay(year, month); i++)
		{
			cout << "    ";
		}

		for (int i = 1; i <= dayOfMonth(year, month); i++)
		{
			cout << setw(3) << i << " ";
			if ((i + firstDay(year, month) - 1) % 7 == 0)
			{
				backline(10, lineTemp);
			}
		}
		month += 2;
		line = lineTemp = lineGoto++ * 10;
	}
	cout << "\n\n\n\t Welcome to use my app again !\n\n\t ";
}