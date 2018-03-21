#include<iostream>
#include<windows.h>

using namespace std;

class t
{
public:
      virtual void  Try()
		{
		  cout<<"这是父类"<<endl;
	  }
};
class tr :public t
{
public:
      void Try()
		{
		  cout<<"这是子类"<<endl;
	  }
};
int main()
{
	t *a;
	a=new t;
	a->Try();
	a=new tr;
	a->Try();
	return 0;
}
//对动态多态的实现：对于父类和子类中的同名同参数函数可以用虚函数来准确的调用他们
