#include<iostream>
#include<string>
using namespace std;
int main()
{
	string a1="beautiful",a2="world",a3,a4;
	a3.assign(a2,3,6);        //�Ѵ�a2�Ե�������ʼ���ȡ6����ֵ��a3
	a3.assign(a1,2,string::npos);     //�Ѵ�a1�Եڶ�����ʼ�����ֵ��a3
	a3.assign("smart",2);           //���ַ�����ǰ������ֵ��a3������������Ⱦ���ȫ��ֵ
	a3.assign(2,'s');                //��2��s��ֵ��a3
	a1.swap(a2);                      //����a1��a2��ֵ
	a1.append(a2);             //append���÷�ͬassign
	a1.insert(2,"celcver");       //����
	a1.erase(6,1);                  //ɾ���ӵ�������ʼ��һ���ַ�
	a1.erase(7);                      //ɾ�����߸��Ժ���ַ�
	cout<<a1<<endl;
	return 0;
}
//�ַ��������޶ࡣ����һ��һ������