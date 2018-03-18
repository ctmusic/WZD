#include <iostream>
#include <string.h>

using namespace std;

struct{
    char number[15];                  //学号
    char name[30];                //姓名
    char idcard[30];                 //身份证
    char address[100];                   //地址
}stu[30];

int main()
{
    int q=0,i;
loop:
    cout << "1--身份证查找方式" << endl;
    cout << "2--学生学号查找方式" << endl;
    cout << "3--存储学生信息" << endl;
    char g[50],ptr[100];
    cin >> g;
    if(strlen(g)>1)
    {
        system("cls");
        cout << "对不起，你的输入有误，请重新输入！" << endl;
        goto loop;
    }

    switch(g[0])
    {
    case '1':
    {
        system("cls");
        cout << "请输入要查找的身份证：" << endl;
        cin >> ptr;

        for(i=0;i<30;i++)
        {
            if (strcmp(ptr,stu[i].idcard)==0)
            {
                cout << "学号：" << stu[i].number << "      姓名：" << stu[i].name << endl;
                cout << "身份证号:" << stu[i].idcard << endl;
                cout << "地址:" << stu[i].address << endl << endl << endl;
                goto loop;
            }
        }
        cout << "对不起，您要查找的内容不存在，请确认您的输入是否正确！" << endl;
        goto loop;
    }
    case '2':
    {
        system("cls");
        cout << "请输入您要查找的学号：" << endl;
        cin >> ptr;

        for(i=0;i<30;i++)
        {
            if (strcmp(ptr,stu[i].number)==0)
            {
                cout << "学号：" << stu[i].number << "      姓名：" << stu[i].name << endl;
                cout << "身份证号:" << stu[i].idcard << endl;
                cout << "地址:" << stu[i].address << endl << endl << endl;
                goto loop;
            }
        }
        cout << "对不起，您要查找的内容不存在，请确认您的输入是否正确！" << endl;
        goto loop;
    }
    case '3':
    {
        cout << "请输入学号:" << endl;
        cin >> stu[q].number;
        cout << "请输入姓名：" << endl;
        cin >> stu[q].name;
        cout << "请输入身份证：" << endl;
        cin >> stu[q].idcard;
        cout << "请输入地址：" << endl;
        cin >> stu[q].address;
        system("cls");
        cout << "信息输入完毕" << endl;
        q++;
        goto loop;
    }
    default:
    {
        system("cls");
        cout << "对不起，您的输入有误，请重新输入！" << endl;
        goto loop;
    }
    }
    return 0;
}

