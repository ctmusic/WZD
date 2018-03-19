#include<iostream>
#include <windows.h> 
#include<iomanip>
using namespace std;
class wnl
{
	
public:
	int year;
	int n;
	wnl(){year=0;n=0;}
	void runnian(int b,int m[ ])
	{
		if((b%4==0&&b%100!=0)||b%400==0)
		m[1]=29;
	}
	void hang(int x,int y,int k[],int m[])
	{
		int i,j;
		if(x>12)
			cout<<"Error";
		else if(y==0)
			cout<<"                  "<<x<<"月";
		else if(y==1)
			 cout<<" 日 一 二 三 四 五 六";
		else if(y==2)
		{
			for(i=0;i<k[x-1];i++)
				cout<<"   ";
			for(i=1;i<8-k[x-1];i++)
				cout<<setw(2)<<setiosflags(ios::right)<<i<<" ";      
		}
		else
		{
			j=(y-2)*7-k[x-1]+1;
			for(i=0;i<7;i++,j++)
			{
				if(j<=m[x-1])
					cout<<setw(2)<<setiosflags(ios::right)<<j<<" ";
				else
					cout<<"   ";
			}
		}
	}
	void mainpart()
	{
		int i,j,l=-1;
		int m[12]={31,28,31,30,31,30,31,31,30,31,30,31};
		int k[12];
		cin>>year>>n;
		runnian(year,m);
		k[0]=((year-1)*365+(year-1)/4-(year-1)/100+(year-1)/400+1)%7;
		for(i=1;i<12;i++)
		{
			k[i]=(k[i-1]+m[i-1])%7;
		}
		for(j=0;j<(12/n+(12%n!=0))*8;j++)
		{
			if(j%8==0)
				l++;
			for(i=1;i<=n;i++)
			{
				hang(i+l*n,j%8,k,m);
				cout<<"  ";
			}
				cout<<"\n";
		}
	}
};


int main()
{
	wnl test1;
	system("mode con cols=200 lines=50");
	test1.mainpart();
}