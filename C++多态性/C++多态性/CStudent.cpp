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
	cout << "学生姓名: " << studentName << endl;
	cout << "学生总分数: " << totalCrediHour << endl;
	cout << "已修完课程总数: " << totalCourse << endl;
	cout << "学生平均分: " << averScore;
}