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
{cout<<"a��������";
}
void data::zz(char b)
{cout<<"b�����ַ�";
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
//ͬһ��������ʹ�ò�ͬ������ʵ�ֲ�ͬ���� 
