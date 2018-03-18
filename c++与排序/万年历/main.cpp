#include<iostream> 
#include <iomanip> 
#include<windows.h>
using namespace std;
int f; 
class data 
{ 
private: 
    int year; 
     
public: 
    void getyear();              //������� 
    int leapyear();             //�ж����� 
    int  fday();                //�жϸ����Ԫ�� 
    int monthday(int i);             //ÿ���µ����� 
    void display();         //��ʾ����� 
	void move(int ,int);
}; 
char* weeked[7]={"��һ","�ܶ�","����","����","����","����","����"};   
void data::move(int a,int b)
{
	HANDLE hout;  
	COORD coord;  
	coord.X=a;  
    coord.Y=b;  
    hout=GetStdHandle(STD_OUTPUT_HANDLE);  
    SetConsoleCursorPosition(hout,coord);  
 

}
void data::getyear()   //������� 
{ 
    cout<<"������ݣ�"; 
    cin>>year; 
} 
int data::leapyear()     //�ж����� 
{	if(year%100==0&&year%400!=0)
        return 1;
	else
		return 0;
 } 
 int data::fday()   //�ж�Ԫ�� 
 {	int y=(365*year+year/4-year/100+year/400)%7+1;
	return y;
 }
 int data::monthday(int i)    //�ж�ÿ������ 
 {if(i==1||i==3||i==5||i==7||i==8||i==10||i==12)
    return 31;
else if(i==2)
         if(leapyear())
         return 29;
         else
         return 28;
else
    return 30;
 }
void data::display()   //��ʾ 
 {
 int n=fday();
 cout<<endl<<"��Ҫ���е�������";
 cin>>f;
  for(int i=1;i<=12;i++)
  {
	int s=1;
	cout<<endl;
	if(i%f==1)                                    //λ��ȷ��
		move(15,10*((i-1)/f)+1);
	else if(f==1)
		cout<<"";
	else
		move(50*((i-1)%f)+20,10*((i-1)/f)+1);
	cout<<setw(5)<<i<<"��"<<endl;
	if(i%f==1)                                   //λ��ȷ��
		move(1,10*((i-1)/f)+2);
	else if(f==1)
		cout<<"";
	else
		move(50*((i-1)%f)+20,10*((i-1)/f)+2);
	for(int z=0;z<7;z++)
         cout<<weeked[z]<<"   ";
	cout<<endl;
	if(i%f==1)                                   //λ��ȷ��
		move(1,10*((i-1)/f)+3);
	else if(f==1)
		cout<<"";
	else
		move(50*((i-1)%f)+20,10*((i-1)/f)+3);
	for(int x=1;x<=n;x++,s++)
      cout<<"       ";
	for(int c=1;c<=monthday(i);c++,s++)
	{
  	     cout<<c;
  	     if(c<10)
  	         cout<<"      ";
  	    else
  	         cout<<"     ";
  	     if(s%7==0)
		 {
  	          cout<<endl;
			  if(i%f==1)                                   //λ��ȷ��
				  move(1,10*((i-1)/f)+s/7+3);
			  else if(f==1)
				  cout<<"";
			  else
				  move(50*((i-1)%f)+20,10*((i-1)/f)+s/7+3);
		 }
  }
  n=s%7;
  
  cout<<endl;
  if(i%f==1)                                   //λ��ȷ��
		move(1,10*((i-1)/f)+s/7+4);
  else if(f==1)
		cout<<"";
  else
		move(50*((i-1)%f)+20,10*((i-1)/f)+s/7+4);
  cout<<"�ӨӨӨӨӨӨӨӨӨӨӨӨӨӨӨӨӨӨӨӨӨӨӨ�"<<endl;
  }
 }
int main(void)
{
	data a;
	a.getyear();  //�û����� 
	a.display();   //�������� 
	return 0;
} 

//�ܽ��װ�������ԣ����û�ֻ���õ����루getyear����ֻ�ܿ��������diaplay���������ľ�����̶������к������

