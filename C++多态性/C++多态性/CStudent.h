#pragma once
class CStudent
{
public:
	void AddCourse(int crediHour, float source);//学时 && 分数
	void showStudentInformation(void);
	virtual float calcTuition(void)
	{
		cout << "普通学生学费: ";
		return 4500.0;
	}
protected:
	string studentName;
	int    totalCourse;
	float  averScore;
	int    totalCrediHour;
};

