#include<iostream>
#include<cstdio>  
#include<stack>  
#include<string>  
#include<cstring>  
#include<cmath>  
#include<ctype.h>  
#include<iostream>
using namespace std;

stack <double> num;
stack <char> cha;
char str[999];
char tra[999];

void ad()
{
	double d1,d2;     //接收数据栈内要计算的两个数据
	char c;           //接收字符栈内要做计算的运算符
	c=cha.top();          //switch内不让用top函数，只能用char类型来接收栈内字符
//	cout<<endl<<"c1 do   "<<num.top()<<"  "<<cha.top()<<endl;
	while(c!='(')
	{
		d1=num.top();    //接收栈内两个要做计算的数据、接收完后直接将数据从栈中弹出
		num.pop();
		d2=num.top();
		num.pop();     
//		cout<<endl<<"c1 while do  "<<d1<<"  "<<cha.top()<<"   "<<d2<<endl;
		switch (c)     //判断运算符，然后进行运算
		{
		case '+':
			d2+=d1;
			break;
		case '-':
			d2-=d1;
			break;
		case '*':
			d2*=d1;
			break;
		case '/':
			d2/=d1;
			break;
		}
		num.push(d2);    //两数计算得出的数据入栈
//		cout<<"  top is "<<d2<<"  pop is "<<cha.top();
		cha.pop();       //使用过的运算符弹出
		c=cha.top();     //读取下一个运算符、在使用+和-的时候用不到
//		cout<<"  pop then is  "<<c<<endl;
	}
}
void ride()
{
//	cout<<endl<<"c2 do  "<<num.top()<<"  "<<cha.top()<<endl;
	double d1,d2;
	char c;
	c=cha.top();
	while(c=='*'||c=='/')
	{
		d1=num.top();
		num.pop();
		d2=num.top();
		num.pop();
//		cout<<endl<<"c2  while do   "<<d1<<"  "<<c<<"  "<<d2<<endl;
		if(c=='*')
			d2*=d1;
		else if(c=='/')
			d2/=d1;
		num.push(d2);
		cha.pop();
		c=cha.top();
	}
}
void main()
{
	cha.push('(');
	int k=0;
	double fd;
	cout<<"输入一串算式"<<endl;
	cin>>str;
	char pp[2]="=";
	strcat(str,pp);               //在算式最后加个=号
	for(int i=0;str[i];i++)
	{
		if(str[i]>='0'&&str[i]<='9'||str[i]=='.')
		{
			tra[k++]=str[i];
			continue;              //把由多个字符组成的一个数据存入字符串中
		}
		tra[k]=0;
		if(tra[0]!=0)
		{
			fd=atof(tra);          //把数据转化为double型
			num.push(fd);          //数据入栈
//			cout<<endl<<"push is  "<<fd<<endl;
		}
		k=0;
		switch(str[i])             //对运算符进行判断
		{
		case '+':
			ad();
			cha.push('+');
			break;
		case '-':
			ad();
			cha.push('-');
			break;
		case '*':
			ride();
			cha.push('*');
			break;
		case '/':
			ride();
			cha.push('/');
			break;
		case '(':
			cha.push('(');
			break;
		case ')':
//			cout<<endl<<"do  )"<<endl;
			ad();
			cha.pop();
//			cout<<endl<<"do ) then is"<<num.top()<<"  "<<cha.top()<<endl;
			break;
		case '=':
			ad();
			cha.pop();
			break;
		}
	}
	cout<<num.top();
}
