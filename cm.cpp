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
	double d1,d2;     //��������ջ��Ҫ�������������
	char c;           //�����ַ�ջ��Ҫ������������
	c=cha.top();          //switch�ڲ�����top������ֻ����char����������ջ���ַ�
//	cout<<endl<<"c1 do   "<<num.top()<<"  "<<cha.top()<<endl;
	while(c!='(')
	{
		d1=num.top();    //����ջ������Ҫ����������ݡ��������ֱ�ӽ����ݴ�ջ�е���
		num.pop();
		d2=num.top();
		num.pop();     
//		cout<<endl<<"c1 while do  "<<d1<<"  "<<cha.top()<<"   "<<d2<<endl;
		switch (c)     //�ж��������Ȼ���������
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
		num.push(d2);    //��������ó���������ջ
//		cout<<"  top is "<<d2<<"  pop is "<<cha.top();
		cha.pop();       //ʹ�ù������������
		c=cha.top();     //��ȡ��һ�����������ʹ��+��-��ʱ���ò���
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
	cout<<"����һ����ʽ"<<endl;
	cin>>str;
	char pp[2]="=";
	strcat(str,pp);               //����ʽ���Ӹ�=��
	for(int i=0;str[i];i++)
	{
		if(str[i]>='0'&&str[i]<='9'||str[i]=='.')
		{
			tra[k++]=str[i];
			continue;              //���ɶ���ַ���ɵ�һ�����ݴ����ַ�����
		}
		tra[k]=0;
		if(tra[0]!=0)
		{
			fd=atof(tra);          //������ת��Ϊdouble��
			num.push(fd);          //������ջ
//			cout<<endl<<"push is  "<<fd<<endl;
		}
		k=0;
		switch(str[i])             //������������ж�
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
