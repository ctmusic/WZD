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
			cout<<"早上好，Masta！";
		}
		else if((l->tm_hour>=12)&&(l->tm_hour<=13))
		{
			cout<<"Masta，中午了该吃饭了";
		}
		
		else if((l->tm_hour>13)&&(l->tm_hour<=17))
		{
			cout<<"Masta，下午想做点什么呢？";
		}
		else if((l->tm_hour>17)&&(l->tm_hour<20))
		{
			go(70,20);
			cout<<"晚餐时间了呢，Masta，Masta是想先洗澡还是先吃饭还是...先——吃——我？o(≧v≦)o";
		}
		else
		{
			cout<<"Masta,该就寝了,快躺下！~\(≧▽≦)/~";
		}
		getch();
		
	}
	virtual void quest()
	{
		char a;
		go(87,23);
		cout<<" 问题啊，您随便问吧，Masta~ ";	
		getch();
		go(72,26);
		cout<<"A. 你是我的什么？\t\t\t\tB. 我是你的什么？";
		a=getch();
		system("cls");
		go(85,20);
		if((a=='a')||(a=='A'))
			cout<<"我是你可爱的仆人呀！My Masta！";
		else if((a=='b')||(a=='B'))
			cout<<"您是我最最最最最最喜欢的Masta！";
		else
			cout<<"Masta你在说什么，人家听不懂啦。";
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
			cout<<"怠惰！快点给我去干活！";
		else if((l->tm_hour>=12)&&(l->tm_hour<=13))
			cout<<"你这家伙，中午没饭吃了！";
		
		else if((l->tm_hour>13)&&(l->tm_hour<=17))
			cout<<"马桶刷了吗？赶紧去！";
		else if((l->tm_hour>17)&&(l->tm_hour<20))
			cout<<"那里的干面包是你的晚饭。";
		else
			cout<<"你就到马厩睡吧，明天早起干活，听到没有！";
		getch();



	}
	void quest()
	{
		char a;
		go(85,23);
		cout<<"问题？赶紧去干活，还费什么话！";
		getch();
		go(80,26);
		cout<<"A. 你是我的什么？\t\t\t\tB. 我是你的什么？";
		a=getch();
		system("cls");
		go(85,20);
		if((a=='a')||(a=='A'))
			cout<<"你这家伙敢这样和你的主人说话？又想挨鞭子了吧！";
		else if((a=='b')||(a=='B'))
			cout<<"卑贱的奴隶，快去赶你该干的事！";
		else
			cout<<"神神叨叨说什么啊，滚去干活！";
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
		cout<<"请选择模式\n"<<"A.Masta\t\t\tB.Slave";
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
