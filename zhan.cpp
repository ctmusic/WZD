#include<iostream>
#include<stack>
using namespace std;
int main()
{
	int i;
	stack <int> a;
	while(i!=0)
	{
		cin>>i;
		a.push(i);         //��������ջ
	}
	cout<<endl<<"ջ�������У�";
	while(!a.empty())       //�ж�ջ�ǲ��ǿյ�
	{
		cout<<a.top();       //��ջ����ȡһ������
		a.pop();              //��ջ�����ݵ���
	}
	cout<<endl<<"ջ���ڴ��С"<<a.size();       //����ջ��Ԫ�صĴ�С��ջ�ǿյ�ʱ�����0
	return 0;
}