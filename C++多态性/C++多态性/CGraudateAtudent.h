#pragma once
#include "CTutorial.h"
#include "CStudent.h"
class CGraudateAtudent:public CStudent
{
public:
	CTutorial& getTutorial(void)
	{
		return tutoria;
	}
	void showStudentInformation(void);
	float calcTuition(void)
	{
		cout << "�о���ѧ��: ";
		return 2000;
	}
protected:
	CTutorial tutoria;
};

