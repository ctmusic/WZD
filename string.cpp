#include "stdio.h"
#include "string.h"
#include "stdlib.h"
 
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
 
#define MAXSIZE 40 
 
typedef int Status;    
typedef char String[MAXSIZE] ;
void StrPrint(String T)
{
    int i;
    for(i=1;i<=T[0];i++)
        printf("%c",T[i]);
    printf("\n");
}
 
Status StrEmpty(String S)
{
    if(S[0]==0)
        return TRUE;
    else
        return FALSE;
}
 

Status StrAssign(String T,char *chars)
{
    int i;
    if(strlen(chars)>MAXSIZE)
        return ERROR;
    else
    {
        T[0]=strlen(chars);
        for(i=1;i<=T[0];i++)
            T[i]=*(chars+i-1);
        return OK;
    }
}
 

int StrLength(String S)
{
    return S[0];
}
 
int StrCompare(String S,String T)
{
    int i;
    for(i=1;i<=S[0]&&i<=T[0];++i)
        if(S[i]!=T[i])
            return S[i]-T[i];
    return S[0]-T[0];
}
 

Status Concat(String T,String S1,String S2)
{
    int i;
    if(S1[0]+S2[0]<=MAXSIZE)
    { 
        for(i=1;i<=S1[0];i++)
            T[i]=S1[i];
        for(i=1;i<=S2[0];i++)
            T[S1[0]+i]=S2[i];
        T[0]=S1[0]+S2[0];
        return TRUE;
    }
    else
    {
        for(i=1;i<=S1[0];i++)
            T[i]=S1[i];
        for(i=1;i<=MAXSIZE-S1[0];i++)
            T[S1[0]+i]=S2[i];
        T[0]=MAXSIZE;
        return FALSE;
    }
}
 

Status SubString(String Sub,String S,int pos,int len)
{
    int i;
    if(pos < 1||pos>S[0]||len < 0||len>S[0]-pos+1)
        return ERROR;
    for(i=1;i<=len;i++)
        Sub[i]=S[pos+i-1];
    Sub[0]=len;
    return OK;
}
 
Status StrInsert(String S,int pos,String T)
{
    int i;
    if(pos< 1||pos>S[0]+1)
        return ERROR;
    if(S[0]+T[0]<=MAXSIZE)
    { 
        for(i=S[0];i>=pos;i--)
            S[i+T[0]]=S[i];
        for(i=pos;i < pos+T[0];i++)
            S[i]=T[i-pos+1];
        S[0]=S[0]+T[0];
        return TRUE;
    }
    else
    { 
        for(i=MAXSIZE;i<=pos;i--)
            S[i]=S[i-T[0]];
        for(i=pos;i < pos+T[0];i++)
            S[i]=T[i-pos+1];
        S[0]=MAXSIZE;
        return FALSE;
    }
}
 

Status StrDelete(String S,int pos,int len)
{
    int i;
    if(pos < 1||pos>S[0]-len+1||len < 0)
        return ERROR;
    for(i=pos+len;i<=S[0];i++)
        S[i-len]=S[i];
    S[0]-=len;
    return OK;
}
 

 
int main()
{
  int i, j, opp, pos;
  char s, str;
    String t,s1,s2,sub;
    Status k;
 
  printf("\n1. 生成串 \n2. 求串长 \n3. 串比较 ");
  printf("\n4. 串连接 ");
  printf("\n0. 退出 \n请选择你的操作：\n");
  while(opp != '0')
  {
    scanf("%d",&opp);
    switch(opp)
    {
    case 1:
      k=StrAssign(s1,"myLastMonth");
      if(!k)
      {
        printf("串长超过MAXSIZE(=%d)\n",MAXSIZE);
        exit(0);
      }
      printf("串s1为：");
      StrPrint(s1);
      printf("\n");
      printf("串2为: isGoodAndAlittle~\n");
      break;
 
    case 2:
      printf("串s1长为%d \n",StrLength(s1));
      break;
 
    case 3:
      k=StrAssign(s2,"isGoodAndAlittle~");
      if(!k)
      {
        printf("串长超过MAXSIZE(%d)\n",MAXSIZE);
        exit(0);
      }
      printf("串s2为：");
      StrPrint(s2);
      printf("\n");
 
      i=StrCompare(s1,s2);
      if(i < 0)
        s=' < ';
      else if(i==0)
        s='=';
      else
        s='>';
      printf("串s1%c串s2\n",s);
      break;
 
    case 4:
      Concat(t,s1,s2);
      StrPrint(t);
      break;
    case 5:
      printf("主串s1为: ");
      StrPrint(s1);
      k=StrAssign(sub,"lol");
      printf("子串sub为: ");
      StrPrint(sub);
      printf("请输入要插入的位置: ");
      scanf("%d", &pos);
      StrInsert(s1,pos,sub);
      StrPrint(s1);
      break;
 
    case 6:
      printf("从串s1的第pos个字符起,删除len个字符，请输入pos: \n");
      scanf("%d", &i);
      printf("再输入len: \n");
      scanf("%d", &j);
      StrDelete(s1,i,j);
      StrPrint(s1);
      break;
 
 
    case 0:
      exit(0);
    }
  }
}
