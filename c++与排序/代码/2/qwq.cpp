#include <iostream>
#include <string.h>

using namespace std;

struct{
    char number[15];                  //ѧ��
    char name[30];                //����
    char idcard[30];                 //���֤
    char address[100];                   //��ַ
}stu[30];

int main()
{
    int q=0,i;
loop:
    cout << "1--���֤���ҷ�ʽ" << endl;
    cout << "2--ѧ��ѧ�Ų��ҷ�ʽ" << endl;
    cout << "3--�洢ѧ����Ϣ" << endl;
    char g[50],ptr[100];
    cin >> g;
    if(strlen(g)>1)
    {
        system("cls");
        cout << "�Բ�����������������������룡" << endl;
        goto loop;
    }

    switch(g[0])
    {
    case '1':
    {
        system("cls");
        cout << "������Ҫ���ҵ����֤��" << endl;
        cin >> ptr;

        for(i=0;i<30;i++)
        {
            if (strcmp(ptr,stu[i].idcard)==0)
            {
                cout << "ѧ�ţ�" << stu[i].number << "      ������" << stu[i].name << endl;
                cout << "���֤��:" << stu[i].idcard << endl;
                cout << "��ַ:" << stu[i].address << endl << endl << endl;
                goto loop;
            }
        }
        cout << "�Բ�����Ҫ���ҵ����ݲ����ڣ���ȷ�����������Ƿ���ȷ��" << endl;
        goto loop;
    }
    case '2':
    {
        system("cls");
        cout << "��������Ҫ���ҵ�ѧ�ţ�" << endl;
        cin >> ptr;

        for(i=0;i<30;i++)
        {
            if (strcmp(ptr,stu[i].number)==0)
            {
                cout << "ѧ�ţ�" << stu[i].number << "      ������" << stu[i].name << endl;
                cout << "���֤��:" << stu[i].idcard << endl;
                cout << "��ַ:" << stu[i].address << endl << endl << endl;
                goto loop;
            }
        }
        cout << "�Բ�����Ҫ���ҵ����ݲ����ڣ���ȷ�����������Ƿ���ȷ��" << endl;
        goto loop;
    }
    case '3':
    {
        cout << "������ѧ��:" << endl;
        cin >> stu[q].number;
        cout << "������������" << endl;
        cin >> stu[q].name;
        cout << "���������֤��" << endl;
        cin >> stu[q].idcard;
        cout << "�������ַ��" << endl;
        cin >> stu[q].address;
        system("cls");
        cout << "��Ϣ�������" << endl;
        q++;
        goto loop;
    }
    default:
    {
        system("cls");
        cout << "�Բ������������������������룡" << endl;
        goto loop;
    }
    }
    return 0;
}

