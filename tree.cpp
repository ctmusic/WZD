#include<iostream>
using namespace std;
typedef struct tr
{
	int num;
	struct tr *l;
	struct tr *r;
}*tre;
tre set()
{
	tre rot=new struct tr;
	int a;
	cin>>a;
	if(a==0)
	{
		rot=NULL;
	}
	else
	{
	rot->num=a;
	rot->l=set();
	rot->r=set();
	}
	return rot;
}
void look(tre rot)
{
	if(rot==NULL)
		return;
	else
	{
		cout<<rot->num;
		look(rot->l);
		look(rot->r);
	}
}

int main()
{
	tre rot;
	rot=set();
	look(rot);
}
