#pragma once
class CStudent
{
public:
	void AddCourse(int crediHour, float source);//ѧʱ && ����
	void showStudentInformation(void);
	virtual float calcTuition(void)
	{
		cout << "��ͨѧ��ѧ��: ";
		return 4500.0;
	}
protected:
	string studentName;
	int    totalCourse;
	float  averScore;
	int    totalCrediHour;
};

