#include<iostream>
#include<string>
using namespace std;
const int StackSize=128; 
int p(char fuhao); //符号优先级
float ca(string arr,int n); //结果
template<class Data>
class Stack
{
	public:
		Stack(){top=-1;}
		~Stack(){};
		void Push(Data x);
		void Pop();
		Data GetTop();
		int isempty();
	private:
		int top;
		Data data[StackSize];
};
template<class Data>
void Stack<Data>::Push (Data x)
{
	if(top==StackSize-1)
		throw"上溢";
	top++;
	data[top]=x;
}
template<class Data>
void Stack<Data>::Pop()
{
	if(top==-1)
		throw"下溢";
	data[top--];
}
template<class Data>
Data Stack<Data>::GetTop()
{
	if(top!=-1)
		return data[top];
	throw"空";
}
template<class Data>
int Stack<Data>::isempty()
{
	if(top==-1)
		return 1;
	else
		return 0;
}
int p(char fuhao)
{
	if(fuhao=='+'||fuhao=='-')
		return 1;
	if(fuhao=='*'||fuhao=='/')
		return 2;
	return 0;
}
float ca(string arr[],int n)
{
	Stack<float>S;
	int i=0,k=0;
	float f1,f2;
	for(i=0;i<n;i++)
	{
		if(arr[i]!="+"&&arr[i]!="-"&&arr[i]!="*"&&arr[i]!="/")
		{
			S.Push (atof(arr[i].c_str()));
		}
		else
		{
			if(arr[i]=="+")
			{
				f1=S.GetTop();
				S.Pop();
				f2=S.GetTop();
				S.Pop();
				S.Push(f1+f2);
			}
			else if(arr[i]=="-")
			{
                f1=S.GetTop();
				S.Pop();
				f2=S.GetTop();
				S.Pop();
				S.Push(f2-f1);
		}
		else if(arr[i]=="*")
		{
                f1=S.GetTop();
				S.Pop();
				f2=S.GetTop();
				S.Pop();
				S.Push(f2*f1);
	}

	else if(arr[i]=="/")
		{
                f1=S.GetTop();
				S.Pop();
				f2=S.GetTop();
				S.Pop();
				S.Push(f2/f1);
	}
		}
	}
	return S.GetTop();
}
void main()
{
	Stack<char>S1;
	string m;
	string shuzi="";
	char fuhao;
	int i=0,j=0,flag=1;
	string arr[50];
	while(flag)
	{
		cout<<"请输入式子(负号为_):";
		cin>>m;
		for(i=0;i<m.length();i++)
		{
			while(i<m.length()&&((m.at(i)>='0'&&m.at(i)<='9')||m.at(i)=='.'||m.at(i)=='_'))
			{
				if(m.at(i)=='_')
				{
					shuzi="-";
					i++;
				}
				shuzi+=m.at(i);
				i++;
			}
			if(!shuzi.empty())
			{
				arr[j]=shuzi;
				j++;
				shuzi="";
			}
			if(i<m.length())
			{
				fuhao=m.at(i);
				if(fuhao=='(')
				{
					S1.Push('(');
				}
				else
				{
					if(fuhao==')')
					{
						while(S1.GetTop()!='(')
						{
							arr[j]=S1.GetTop();
							S1.Pop();
							j++;
						}
						S1.Pop();

					}
					else
					{
						if(S1.isempty())
						{
							S1.Push(fuhao);
						}
						else
						{
							if(p(fuhao)>p(S1.GetTop()))
							{
								S1.Push(fuhao);
							}
							else
							{
								while(!S1.isempty()&&(p(fuhao)<=p(S1.GetTop())))
								{
									arr[j]=S1.GetTop();
									S1.Pop();
									j++;
								}
								S1.Push(fuhao);
							}
						}
					}
				}
			}

		}
		while(!S1.isempty())
		{
			arr[j]=S1.GetTop();
			S1.Pop();
			j++;
		}
		cout<<"结果为:"<<ca(arr,j)<<endl;
		cout<<"是否继续"<<endl;
		cout<<"1,是"<<endl;
		cout<<"0,否"<<endl;
		cin>>flag;
		system("cls");
	}

}
