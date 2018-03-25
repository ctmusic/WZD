#include "stdafx.h"
#include "CTutorial.h"


void CTutorial::setTutorialName(string tutorialName)
{
	this->tutorialName = tutorialName;
}

void CTutorial::showTutorialName(void)
{
	cout << tutorialName;
}
