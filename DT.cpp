#include<iostream>
#include<windows.h>

using namespace std;

class t
{
public:
      virtual void  Try()
		{
		  cout<<"���Ǹ���"<<endl;
	  }
};
class tr :public t
{
public:
      void Try()
		{
		  cout<<"��������"<<endl;
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
//�Զ�̬��̬��ʵ�֣����ڸ���������е�ͬ��ͬ���������������麯����׼ȷ�ĵ�������
