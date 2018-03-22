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
		a.push(i);         //把数据入栈
	}
	cout<<endl<<"栈内数据有：";
	while(!a.empty())       //判断栈是不是空的
	{
		cout<<a.top();       //从栈顶读取一个数据
		a.pop();              //把栈内数据弹出
	}
	cout<<endl<<"栈的内存大小"<<a.size();       //返回栈内元素的大小、栈是空的时候就是0
	return 0;
}