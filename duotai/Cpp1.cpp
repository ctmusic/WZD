#include<iostream>
#include <time.h>
#include<windows.h>
#include<conio.h>
#include<stdio.h>
#include <stdlib.h>
using namespace std;
class masta
{
public:
	virtual void title ()
	{
		time_t nt;
		nt=time(NULL);
		struct tm *l;

		l=localtime(&nt);
		go(90,20);
		if((l->tm_hour>=6)&&(l->tm_hour<=8))
		{
			go(100,20);
			cout<<"���Ϻã�Masta��";
		}
		else if((l->tm_hour>=12)&&(l->tm_hour<=13))
		{
			cout<<"Masta�������˸óԷ���";
		}
		
		else if((l->tm_hour>13)&&(l->tm_hour<=17))
		{
			cout<<"Masta������������ʲô�أ�";
		}
		else if((l->tm_hour>17)&&(l->tm_hour<20))
		{
			go(70,20);
			cout<<"���ʱ�����أ�Masta��Masta������ϴ�軹���ȳԷ�����...�ȡ����ԡ����ң�o(�Rv�Q)o";
		}
		else
		{
			cout<<"Masta,�þ�����,�����£�~\(�R���Q)/~";
		}
		getch();
		
	}
	virtual void quest()
	{
		char a;
		go(87,23);
		cout<<" ���Ⱑ��������ʰɣ�Masta~ ";	
		getch();
		go(72,26);
		cout<<"A. �����ҵ�ʲô��\t\t\t\tB. �������ʲô��";
		a=getch();
		system("cls");
		go(85,20);
		if((a=='a')||(a=='A'))
			cout<<"������ɰ�������ѽ��My Masta��";
		else if((a=='b')||(a=='B'))
			cout<<"������������������ϲ����Masta��";
		else
			cout<<"Masta����˵ʲô���˼�����������";
		getch();
		system("cls");
		quest();

	}
	void go(int x,int y)
	{   
		COORD c;   
		c.X = x - 1;   
		c.Y = y - 1;   
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);   
	}
	
};
class slave:public masta
{
public:
	void title()
	{
		
		time_t nt;
		nt=time(NULL);
		struct tm *l;
		l=localtime(&nt);
		go(90,20);
		if((l->tm_hour>=6)&&(l->tm_hour<=8))
			cout<<"���裡������ȥ�ɻ";
		else if((l->tm_hour>=12)&&(l->tm_hour<=13))
			cout<<"����һ����û�����ˣ�";
		
		else if((l->tm_hour>13)&&(l->tm_hour<=17))
			cout<<"��Ͱˢ���𣿸Ͻ�ȥ��";
		else if((l->tm_hour>17)&&(l->tm_hour<20))
			cout<<"����ĸ�������������";
		else
			cout<<"��͵����˯�ɣ���������ɻ����û�У�";
		getch();



	}
	void quest()
	{
		char a;
		go(85,23);
		cout<<"���⣿�Ͻ�ȥ�ɻ����ʲô����";
		getch();
		go(80,26);
		cout<<"A. �����ҵ�ʲô��\t\t\t\tB. �������ʲô��";
		a=getch();
		system("cls");
		go(85,20);
		if((a=='a')||(a=='A'))
			cout<<"����һ���������������˵�������밤�����˰ɣ�";
		else if((a=='b')||(a=='B'))
			cout<<"������ū������ȥ����øɵ��£�";
		else
			cout<<"����߶߶˵ʲô������ȥ�ɻ";
		getch();
		system("cls");

		quest();

	}
};
void mainpart()
{
	char a;
		masta pa;
		slave pb;
		masta*p;
		HANDLE hout=GetStdHandle(STD_OUTPUT_HANDLE);
		HWND h=GetForegroundWindow();
		ShowWindow(h,SW_MAXIMIZE);
		SetConsoleTextAttribute(hout,FOREGROUND_INTENSITY);
		cout<<"��ѡ��ģʽ\n"<<"A.Masta\t\t\tB.Slave";
		a=getch();
		system("cls");
		if((a=='a')||(a=='A'))
		{
			p=&pa;
			SetConsoleTextAttribute(hout,FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_BLUE);
		}
		else if((a=='b')||(a=='B'))
		{
			SetConsoleTextAttribute(hout,FOREGROUND_INTENSITY|FOREGROUND_GREEN|FOREGROUND_BLUE);
			p=&pb;
		}
		else
		{
			system("cls");
			SetConsoleTextAttribute(hout,FOREGROUND_INTENSITY|FOREGROUND_RED);
			cout<<"Error";
			getch();
			system("cls");
			mainpart();
		}
		p->title();
		p->quest();

}	
int main()
{
		mainpart();
}
