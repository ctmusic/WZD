#include <iostream>
using namespace std;
class Inst //音乐类
{

public:
	virtual void play()
{
		cout<<"Inst::play()"<<endl;
	}
};
class Wind:public Inst //管乐器
{
	virtual void play()

	{
		cout<<"Wind::play()"<<endl;
	}

};
class Gitar:public Inst//吉他
{
	virtual void play()
	{
		cout<<"Gitar::play()"<<endl;
	}



};
void tune(Inst*inst)//调音
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