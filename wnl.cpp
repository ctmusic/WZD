#include<iostream.h>
#include<iomanip.h>
int main()
{
    int a, i, j, n, k, t, w, x, y, z;
    static int d[13][78];
    int m[14] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    char wst[] = "    Sun  Mon  Yue  Wed  Thu  Fri  Sat";
    cout<<"���������:";
	cin>>y; 
 
    if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
        m[2] = 29;
    w = (y + (y - 1) / 4 - (y - 1) / 100 + (y - 1) / 400) % 7; /*����y��Ԫ��Ϊ����w*/
    for (i = 1; i <= 12; i++)
    {
        a = 1;
        for (j = 1; j <= 6; j++)
        {
            for (k = 0; k <= 6; k++)
            {
                while (k<w) k = k + 1;
                d[i][j * 10 + k] = a;  /*����i�µĵ�j�����ڵ�����w������Ϊa*/
                a = a + 1;
                w = k + 1;
                if (w == 7) w = 0;
                if (a>m[i]) break;
            }
            if (a>m[i]) break;
        }
    }
    cout<<"����ÿ����ʾ����(1,2,3,4,5,6): ";
    cin>>x;
    for (k = 1; k <= 16 * x - 3; k++)
        cout<<' ';
    cout<<y;   /*��ӡ���*/
    for (n = 1; n <= 12 / x; n++)
    {
        t = x*(n - 1) + 1;
        cout<<' '<<endl;
        for (z = 1; z <= x; z++)
        {
            for (k = 1; k <= 15; k++)
                cout<<' ';
           cout<<setw(4)<< t + z - 1;   /*�º�*/
            for (k = 1; k <= 14; k++)
                cout<<' ';
        }
        cout<<' '<<endl;
        for (z = 1; z <= x; z++)      /*һ����x����*/
            cout<<setw(2)<<wst;   /*���ڱ���*/
        for (j = 1; j <= 6; j++)
        {
            cout<<' '<<endl;
            for (i = t; i <= t + x - 1; i++)
            {
                cout<<setw(2)<<' ';
                for (k = 0; k <= 6; k++)
                    if (d[i][j * 10 + k] == 0) /*��ȱ���ڿո�*/
                        cout<<setw(5)<<' ';
                    else
                        cout<<setw(5)<< d[i][j * 10 + k];/*����*/
            }
        }
    }
     
    return 0;
}