#include<iostream> 
#include <iomanip> 
using namespace std;
class data 
{ 
private: 
    int year; 
     
public: 
    void getyear();              //输入年份 
    int leapyear();             //判断闰年 
    int  fday();                //判断该年的元旦 
    int monthday(int i);             //每个月的天数 
    void display();                   //显示结果。 
}; 
char* weeked[7]={"周一","周二","周三","周四","周五","周六","周日"};   
void data::getyear()   //输入年份 
{ 
    cout<<"输入年份："; 
    cin>>year; 
} 
int data::leapyear()     //判断闰年 
{	if(year%100==0&&year%400!=0)
        return 1;
	else
		return 0;
 } 
 int data::fday()   //判断元旦 
 {	int y=(365*year+year/4-year/100+year/400)%7+1;
	return y;
 }
 int data::monthday(int i)    //判断每月天数 
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
 void data::display()   //显示 
 {
 int n=fday();
  for(int i=1;i<=12;i++)
  {
  int s=1;
  cout<<endl<<setw(5)<<i<<"月"<<endl;
  for(int z=0;z<7;z++)
         cout<<weeked[z]<<"   ";
  cout<<endl;
  for(int x=1;x<=n;x++,s++)
      cout<<"       ";
  for(int c=1;c<=monthday(i);c++,s++)
  {
  	     cout<<c;
  	     if(c<10)
  	         cout<<"      ";
  	    else
  	         cout<<"     ";
  	     if(s%7==0)\
  	          cout<<endl;
  }
  n=s%7;
  cout<<endl<<"ㄓㄓㄓㄓㄓㄓㄓㄓㄓㄓㄓㄓㄓㄓㄓㄓㄓㄓㄓㄓㄓㄓㄓㄓ"<<endl;
  }
 }
int main(void)
{
	data a;
	a.getyear();  //用户输出 
	a.display();   //计算机输出 
	return 0;
}
//总结封装（隐蔽性）：用户只能用到输入（getyear），只能看到输出（diaplay），运作的具体过程都由类中函数完成

