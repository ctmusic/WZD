#include<iostream>
#include<queue>
using namespace std;
int main()
{
	int i;
	queue<int> q;
	while(i!=0)
	{
		cin>>i;
		q.push(i);               //������ڼ���Ԫ��
	}
	cout<<endl<<"������ռ�ڴ��С:"<<q.size()<<endl;      //�鿴������Ԫ�ظ���
	while(!q.empty())               //�ж϶����Ƿ�Ϊ��
	{
		cout<<q.front();          //���ض��е�һ��Ԫ��
		q.pop();                      //ɾ�����е�һ��Ԫ��
	}
	return 0;
}