#pragma once
#include "stdafx.h"


					/*���ض�̬*/



/*1: ��������  */
int returnResult(int x)
{
	return x;
}
double returnResult(double x)
{
	return x;
}
char returnResult(char x)
{
	return x;
}


/*2: ���������*/
class CComplex
{
public:
	CComplex(double rt = 0, double it = 0)
	{
		real = rt;
		imag = it;
	}
	CComplex operator +(CComplex c)
	{
		return CComplex(this->real + c.real, this->imag + c.imag);
	}
	CComplex operator -(CComplex c)
	{
		return CComplex(this->real - c.real, this->imag - c.imag);
	}
	operator double()
	{
		return sqrt(real*real + imag * imag);
	}
	static void showComplex(CComplex c)
	{
		cout << "(" << c.real << "," << c.imag << ")" << endl;
	}
private:
	double real;
	double imag;
};
