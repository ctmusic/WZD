#include "stdafx.h"
#include "CGraudateAtudent.h"


void CGraudateAtudent::showStudentInformation(void)
{
	this->CStudent::showStudentInformation();
	this->getTutorial().showTutorialName();
	return;
}
