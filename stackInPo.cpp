// stack polish notation conversion infix to postfix
#include<iostream>
#include<cctype>
using namespace std;
struct inpo
{
  char *data;
  int top,size;
   void init(int n)
   {
   size=n;
   data=new char[size];
   top=-1;
   }
   void push(char c)
   {
    if(top==size-1)
    return;
    data[++top]=c;
   }
   char pop()
   {
    if(top==-1)
    return 0;
    return data[top--];
   }
}; 
int getlength(char s[])
{
int i=0;
while(s[i]!='\0')
i++;    
return i;
}
int presi(char c)
{
  switch(c)
  {
    case '^':return 3;
    case '*':return 2;
    case '/':return 2;
    case '+':return 1;
    case '-':return 1;
    default:return 0;
  }
}

bool shouldpop(char top, char current) {
    // Agar stack ka operator zyada powerful hai ya barabar hai, toh pop kar
    return presi(top) >= presi(current);
}
int main()
{
 inpo z;
 char a[100],str[100],i=0,j=0;
 fgets(a,100,stdin);
 int len=getlength(a)-1;
 z.init(len);
 while(i<len)
 {
     if(a[i]=='(')
     {
         z.push(a[i]);
     }
     else if(isalnum(a[i]))
     {
         str[j]=a[i];
         j++ ; 
     }
     else if(presi(a[i])>0)//agar operator mila
     {  
      //jab tak stack ka top greater ya equal hai pop krte jao
      while(z.top!=-1&&z.data[z.top]!='('&&shouldpop(z.data[z.top],a[i]))
      {
        str[j++]=z.pop();
      }
         z.push(a[i]);//as we get operator greater than the top push
     }
     else if(a[i]==')')
     {
      while(z.data[z.top]!='(')
      {
      str[j++]=z.pop();
      }
      z.pop();
     }
     i++;
    }
    while(z.top != -1)
    {
     str[j++] = z.pop();
    }
    str[j] = '\0'; 
    int leng=getlength(str);
    for(int k=0;k<leng;k++)
    {
    cout<<str[k];
    }
    
 }