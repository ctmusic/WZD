#include <iostream>																
#include <string.h>									
using namespace std;
class MS
{
	private:
		char*str;
		int lengh;
	public:
		MS()                                                                    //键盘输入进行初始化 
		{
			char*p;
			cin>>p;
			str=p;
		}
			
		MS(const char*s)                                                        //构造函数来定义串 
		{
			int i;
			if(str)
				delete str; 
			if(s==NULL)
			{
				str=new char[1];
				str[1]='\0';
			}
			else
			{
				str=new char[strlen(s)+1];
				lengh=strlen(s);
				strcpy(str,s);
			}
				
		}
		void opstr()															//输出 
		{
			char*p=str;
			while(*p!='\0')
			{
				cout<<*p;
				p++;
			}
			
		}
		int strl()																//求长度 
		{
			return lengh;
		}
		
		char*lianjie(MS&s1,MS&s2)												//连接两个字符串，也可以用重载+的办法（类似下面重载=） 
		{
			return strcpy(s1.str,s2.str);
			
		}
		MS&operator=(const MS&s)
		{
			str=new char[strlen(s.str)+1];
			strcpy(str,s.str);
			lengh=strlen(s.str);
			return*this;
			
		}
		void zichuan(int n1,int n2)												//取n1位置开始往后n2长度的子串 
		{
			int i;
			char*p;
			p=new char[n2];
			for(i=0;i<n2;i++)
				p[i]=str[n1-1+i];
			str=p;
		}
		void charu(const char*s,int n)											//在n位后插入s字符串 
		{
			int i;
			char *p;
			p=new char[strlen(s)+lengh+1];
			for(i=0;i<n;i++)
				p[i]=str[i];
			for(i=0;i<=strlen(s);i++)
				p[i+n]=s[i];
			for(i=n;i<=lengh;i++)
				p[i+strlen(s)]=str[i];
			str=p;
		} 
};

int main(int argc, char** argv) 
{
	int len;
	
	MS s1("wangpuju");
	MS s2("wangzhongding");
	
	s1.opstr();
	cout<<endl<<"s2=";
	s2.opstr();
	len=s1.strl();
	cout<<endl<<len<<endl;
	s1=s2;
	cout<<"s1=s2 => ";
	s1.opstr();
	s2.zichuan(1,3);
	cout<<endl<<"s2=";
	s2.opstr();
	s1.charu("UIT",4);
	cout<<endl<<"s1=";
	s1.opstr();
	cout<<endl<<"请输入：";
	MS s3;
	cout<<endl<<"s3=";
	s3.opstr();
	
	return 0;
}
