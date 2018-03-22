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
		q.push(i);               //向队列内加入元素
	}
	cout<<endl<<"队列所占内存大小:"<<q.size()<<endl;      //查看队列内元素个数
	while(!q.empty())               //判断队列是否为空
	{
		cout<<q.front();          //返回队列第一个元素
		q.pop();                      //删除队列第一个元素
	}
	return 0;
}