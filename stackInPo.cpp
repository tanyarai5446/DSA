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
     else if(a[i]=='^')
     {
         z.push(a[i]);
     }
     else if(a[i]=='*'||a[i]=='/')
     {
       if(z.data[z.top]=='('||z.data[z.top]=='+'||z.data[z.top]=='-'||z.top==-1)
       { 
         z.push(a[i]);
       }
       else if(a[i]=='*'&& (z.data[z.top]=='^'||z.data[z.top]=='/'))
       {
         while(z.data[z.top]!='('&&z.data[z.top]!='+'&&z.data[z.top]!='-')
         {str[j]=z.pop();j++;}
         z.push(a[i]);
       }
       else if(a[i]=='/'&& (z.data[z.top]=='^'||z.data[z.top]=='*'))
       {
         while(z.data[z.top]!='('&&z.data[z.top]!='+'&&z.data[z.top]!='-')
         {str[j]=z.pop();j++;}
         z.push(a[i]);
       }
     }
     else if(a[i]=='+'||a[i]=='-')
     { 
       if(z.data[z.top]=='('||z.top==-1)
       { 
         z.push(a[i]);
       }
       else if(a[i]=='+'&&(z.data[z.top]=='^'||z.data[z.top]=='*'||z.data[z.top]=='/'||z.data[z.top]=='-'))
       {  
         while(z.data[z.top]!='(')
         {str[j]=z.pop();j++;}
         z.push(a[i]);
       }
       else if(a[i]=='-'&& (z.data[z.top]=='^'||z.data[z.top]=='*'||z.data[z.top]=='/'||z.data[z.top]=='+'))
       {
         while(z.data[z.top]!='(')
         {str[j]=z.pop();j++;}
         z.push(a[i]);
       }
     }
     else if(a[i]==')')
     {
      while(z.data[z.top]!='(')
      {
      str[j]=z.pop();
      j++;
      }
      z.pop();
     }
     i++;
    }
    while(z.top != -1)
    {
     str[j++] = z.pop();
    }
    int leng=getlength(str);
    for(int k=0;k<leng;k++)
    {
    cout<<str[k];
    }
    
 }