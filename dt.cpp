#include <iostream>
using namespace std;
class Inst //������
{

public:
	virtual void play()
{
		cout<<"Inst::play()"<<endl;
	}
};
class Wind:public Inst //������
{
	virtual void play()

	{
		cout<<"Wind::play()"<<endl;
	}

};
class Gitar:public Inst//����
{
	virtual void play()
	{
		cout<<"Gitar::play()"<<endl;
	}



};
void tune(Inst*inst)//����
{
	inst ->play();
}
int main()
{
	Wind f;
	tune(&f);
	Gitar g;
	tune(&g);
	
	return 0;
}