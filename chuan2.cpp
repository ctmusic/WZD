#include<iostream>
using namespace std;

#define MAXSIZE 20

  typedef char String[MAXSIZE + 1]; //��'\0'��β

  /* ����һ����*/

  bool StrAssign(String Dest, char *ptr)

  {
	  cout<<"����һ����"<<endl;

  int i;

  for (i = 0; ptr[i] != '\0' && i < MAXSIZE; i++)

  Dest[i] = ptr[i];

  Dest[i] = '\0';

  return true;

  }

  /* ����һ���ַ��� */

  bool StrCopy(String Dest, String Src)

  {

  cout << "����" << endl;

  int i;

  for (i = 0; Src[i] != '\0' && i < MAXSIZE; i++)

  Dest[i] = Src[i];

  Dest[i] = '\0';

  return true;

  }


int StrLength(String Src)

  {

  int i = 0;

  while (Src[i] != '\0')

  i++;

  return i;

  }


bool StrEmpty(String Src)

  {

  if (StrLength(Src) == 0)

  return true;

  else

  return false;


}

  /* ��Str1>Str2,�򷵻�ֵ>0;��Str1=Str2,�򷵻�ֵ=0;��Str1<Str2,�򷵻�ֵ<0 */

  int StrCompare(String Str1, String Str2)

  {

  int len1 = StrLength(Str1);

  int len2 = StrLength(Str2);

  for (int i = 0; i < len1 && i < len2; i++)

  if (Str1[i] != Str2[i])

  return Str1[i] - Str2[i];

  return len1 - len2;

  }


bool ClearString(String Src)

  {

  for (int i = 0; Src[i] != '\0'; i++)

  Src[i] = '\0';

  return true;

  }

  /* ��Dest����Str1��Str2���Ӷ��ɵ��´�����δ�ضϣ��򷵻�TRUE������FALSE */

  bool StrConcate(String Dest, String Str1, String Str2)

  {

  cout << "����" << endl;

  if (StrLength(Str1) + StrLength(Str2) <= MAXSIZE)

  {

  /* δ�ض� */

  int i, j;

  for (i = 0; Str1[i] != '\0'; i++)

  Dest[i] = Str1[i];

  j = i;

  for (i = 0; Str2[i] != '\0'; i++, j++)

  Dest[j] = Str2[i];

  Dest[j] = '\0';

  return true;

  }

  else //�ض�Str2

  {

  int i, j;

  for (i = 0; Str1[i] != '\0'; i++)

  Dest[i] = Str1[i];

  j = i;

  for (i = 0; Str2[i] != '\0' && j <= MAXSIZE - 1; i++, j++)

  Dest[j] = Str2[i];

  Dest[j] = '\0';

  return false;

  }


}

  /* ��Sub���ش�Src�ĵ�pos���ַ��𳤶�Ϊlen���Ӵ��� */

  bool SubString(String Sub, String Src, int pos, int len)

  {


  if (pos < 1 || pos > StrLength(Src) ||

  len < 0 || len > StrLength(Src) - pos + 1)

  return false;

  int i;

  for (i = 0; i <= len - 1; i++)

  Sub[i] = Src[i + pos - 1];

  Sub[i] = '\0';

  return true;

  }

  /* �����Ӵ�Sub������Src�е�pos���ַ�֮���λ�á���������,��������ֵΪ0�� */

  int Index1(String Src, String Sub, int pos)

  {

  int len1 = StrLength(Src);

  int len2 = StrLength(Sub);

  int i = pos;

  String sub;

  if (pos > 0)

  {

  while (i <= len1 - len2 + 1)

  {

  SubString(sub, Src, i, len2);

  /* ���������� , �򷵻�iֵ */

  if (StrCompare(Sub, sub) == 0)

  return i;

  else/* �����������ȣ�ǰ��λ�� */

  i++;

  }

  }

  return 0;

  }


int Index2(String Src, String Sub, int pos)

  {

  int i = pos - 1;

  int j = 0;

  int len1 = StrLength(Src);

  int len2 = StrLength(Sub);

  while (i <= len1 - 1 && j <= len2 - 1)

  {

  if (Src[i] == Sub[j])/* ����ĸ�������� */

  {

  ++i;

  ++j;

  }

  else

  {

  i = i - j + 1;

  j = 0;

  }

  }


 if (j == len2) 

  return i - len2 + 1;

  else

  return 0;

  }

  /* �ڴ�Src�ĵ�pos���ַ�֮ǰ���봮In�� */

  bool StrInsert(String Src, int pos, String In)

  {

  int i;

  int len1 = StrLength(Src);

  int len2 = StrLength(In);

  if (pos < 1 || pos > len1 + 1)

  return false;


 if (len1 + len2 <= MAXSIZE)

  {

  /* ��ȫ���� */

  for (i = len1; i >= pos - 1; i--)

  Src[i + len2] = Src[i];

  for (i = pos - 1; i < pos + len2 - 1; i++)

  Src[i] = In[i - pos + 1];

  if (pos == len1 + 1) 

  Src[i] = '\0';

  return true;

  }


 else

  {

  /* ���ֲ���,In�ض� */

  for (i = MAXSIZE; i > pos; i--)

  Src[i] = Src[pos + i - MAXSIZE];


 for (i = 0; i < MAXSIZE - pos; i++)

  Src[pos - 1 + i] = In[i];

  return false;

  }

  }

  /* �Ӵ�Src��ɾ����pos���ַ��𳤶�Ϊlen���Ӵ� */

  bool StrDelete(String Src, int pos, int len)

  {

  int i;

  if (pos < 1 || pos > StrLength(Src) - len + 1 || len < 0)

  return false;

  for (i = pos + len - 1; i <= StrLength(Src); i++)

  Src[i - len] = Src[i];

  return true;

  }

  /* ��Re�滻����Src�г��ֵ�������Sub��ȵĲ��ص����Ӵ� */

  bool StrReplace(String Src, String Sub, String Re)

  {

  int i = 1;/* �Ӵ�Src�ĵ�һ���ַ�����Ҵ�Sub */

  if (StrEmpty(Sub))

  return false;

  do

  {

  i = Index1(Src, Sub, i);/* ���iΪ����һ��i֮���ҵ����Ӵ�Sub��λ�� */


 if (i)

  {

  StrDelete(Src, i, StrLength(Sub));/* ɾ���ô�Sub */

  StrInsert(Src, i, Re); /* ��ԭ��Sub��λ�ò��봮Re */

  i += StrLength(Re);/* �ڲ���Ĵ�Re����������Ҵ�Sub */

  }


 }

  while (i);


 return true;

  }


void StrPrint(String Src)

  {

  for (int i = 0; Src[i] != '\0'; i++)

  cout << Src[i];

  cout << endl;


}


int main(void)

  {

  String Str1;

  StrAssign(Str1, "I meet you");

  StrPrint(Str1);


 String Str2;

  StrCopy(Str2, Str1);

  StrPrint(Str2);


 if (!StrEmpty(Str1))

  cout << "��1�ĳ��� " << StrLength(Str1) << endl;


 String Str3;

  StrAssign(Str3, "fuck");


 if (StrCompare(Str1, Str3) > 0)

  cout << "Str1 > Str3" << endl;

  else if (StrCompare(Str1, Str3) == 0)

  cout << "Str1 = Str3" << endl;

  else

  cout << "Str1 < Str3" << endl;


 String Str4, Str5;

  StrAssign(Str4, " fuck you");

  StrConcate(Str5, Str1, Str4);

  StrPrint(Str5);


 String Str6;

  cout << "�õ��Ӵ�" << endl;

  SubString(Str6, Str5, 1, 8);

  StrPrint(Str6);

 StrInsert(Str6, 9, " foolish");

  StrPrint(Str6);

  StrInsert(Str6, 10, "is ");

  StrPrint(Str6);


 StrDelete(Str5, 2, 4);

  StrPrint(Str5);

 return 0;

  }