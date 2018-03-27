#include<iostream>
#include<string>
using namespace std;
int main()
{
	string a1="beautiful",a2="world",a3,a4;
	a3.assign(a2,3,6);        //把串a2自第三个开始向后取6个赋值给a3
	a3.assign(a1,2,string::npos);     //把串a1自第二个开始到最后赋值给a3
	a3.assign("smart",2);           //把字符串的前两个赋值给a3，如果超出长度就完全赋值
	a3.assign(2,'s');                //把2个s赋值给a3
	a1.swap(a2);                      //交换a1和a2的值
	a1.append(a2);             //append的用法同assign
	a1.insert(2,"celcver");       //插入
	a1.erase(6,1);                  //删除从第六个开始后一个字符
	a1.erase(7);                      //删除第七个以后的字符
	cout<<a1<<endl;
	return 0;
}
//字符串函数巨多。。不一个一个打了