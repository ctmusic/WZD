#include <iostream>																
#include <string.h>									
using namespace std;
class MS
{
	private:
		char*str;
		int lengh;
	public:
		MS()                                                                    //����������г�ʼ�� 
		{
			char*p;
			cin>>p;
			str=p;
		}
			
		MS(const char*s)                                                        //���캯�������崮 
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
		void opstr()															//��� 
		{
			char*p=str;
			while(*p!='\0')
			{
				cout<<*p;
				p++;
			}
			
		}
		int strl()																//�󳤶� 
		{
			return lengh;
		}
		
		char*lianjie(MS&s1,MS&s2)												//���������ַ�����Ҳ����������+�İ취��������������=�� 
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
		void zichuan(int n1,int n2)												//ȡn1λ�ÿ�ʼ����n2���ȵ��Ӵ� 
		{
			int i;
			char*p;
			p=new char[n2];
			for(i=0;i<n2;i++)
				p[i]=str[n1-1+i];
			str=p;
		}
		void charu(const char*s,int n)											//��nλ�����s�ַ��� 
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
	cout<<endl<<"�����룺";
	MS s3;
	cout<<endl<<"s3=";
	s3.opstr();
	
	return 0;
}
