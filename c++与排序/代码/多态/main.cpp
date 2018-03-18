#include <iostream>
using namespace std;
class data
{private:
	int a;
	char b;
 public:
 	void zz(int);
 	void zz(char);
};
void data::zz(int a)
{cout<<"a的是数字";
}
void data::zz(char b)
{cout<<"b的是字符";
}
int main(void) {
	data q;
	int a;
	char b;
	q.zz(a);
	cout<<endl;
	q.zz(b);
	return 0;
}
//同一个函数名使用不同参数能实现不同功能 
