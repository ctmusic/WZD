#include "stdafx.h"
#include "CStudent.h"


void CStudent::AddCourse(int crediHour, float source)
{
	totalCrediHour += crediHour;
	averScore = (averScore*totalCourse + source) / (totalCourse + 1);
	totalCourse++;
}

void CStudent::showStudentInformation(void)
{
	cout << "ѧ������: " << studentName << endl;
	cout << "ѧ���ܷ���: " << totalCrediHour << endl;
	cout << "������γ�����: " << totalCourse << endl;
	cout << "ѧ��ƽ����: " << averScore;
}