#include <iostream>
#include<string.h>
#include<windows.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
class fin
{private:
	int move;
	int sign;
	int num;
  public:
  	fin()
  	{num=0;
	  sign=2;
	  }
  	int incase(int n);
};
int fin::incase(int n)
{int c=0;
while(c<n)
{for(move=2;move<=sign;move++)
{if(sign%move==0&&sign!=move)
break;
else if(move==sign)
{cout<<"+"<<sign;
num=num+sign;
++c;
}
}
sign++;
}
return num;
}

int main(void) {
	HANDLE hout;  
	COORD coord;  
	coord.X=10;  
	coord.Y=10;  
	hout=GetStdHandle(STD_OUTPUT_HANDLE);  
	SetConsoleCursorPosition(hout,coord);  
	cout<<"qwertyuio";
	return 0;
}
