//stack infix to prefix
#include<iostream>
#include <cctype>
#include<string>
using namespace std;
struct opr
{
    char *data;
    int top, size;

    void init(int n) {
        size = n;
        data = new char[size];
        top = -1;
    }

    void push(char c) {
        if (top == size - 1) return;
        data[++top] = c;
    }

    char pop() {
        if (top == -1) return 0;
        return data[top--];
    }
};
struct operand
{
  std::string *data;
  int top,size;
   void init(int n)
   {
   size=n;
   data=new std::string[size];
   top=-1;
   }
   void push(std::string c)
   {
    if(top==size-1)
    return;
    data[++top]=c;
   }
   std::string pop()
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
 opr o1 ;
 operand o2;
 char a[100],i=0,j=0;
 std::string arr[4];
 fgets(a,100,stdin);
 int len=getlength(a)-1;
 o1.init(len);o2.init(len);
 while(i<len)
 {
     if(a[i]=='(')
     {
         o1.push(a[i]);
     }
     else if(isalnum(a[i]))
     {
         o2.push(std::string(1,a[i]));
     }
     else if(a[i]=='^')
     {
         o1.push(a[i]);
     }
     else if(a[i]=='*'||a[i]=='/')
     {
       if(o1.data[o1.top]=='('||o1.data[o1.top]=='+'||o1.data[o1.top]=='-'||o1.top==-1)
       { 
         o1.push(a[i]);
       }
       else if(a[i]=='*'&& (o1.data[o1.top]=='^'||o1.data[o1.top]=='/'))
       {
         while(o1.data[o1.top]!='('&&o1.data[o1.top]!='+'&&o1.data[o1.top]!='-')
         {
          arr[0]=o2.pop();
          arr[1]=o2.pop();
          arr[2]=o1.pop();
          arr[3]=arr[2]+arr[1]+arr[0];
          o2.push(arr[3]);
          }
          o1.push(a[i]);
       }
       else if(a[i]=='/'&& (o1.data[o1.top]=='^'||o1.data[o1.top]=='*'))
       {
         while(o1.data[o1.top]!='('&&o1.data[o1.top]!='+'&&o1.data[o1.top]!='-')
         {
          arr[0]=o2.pop();
          arr[1]=o2.pop();
          arr[2]=o1.pop();
          arr[3]=arr[2]+arr[1]+arr[0];
          o2.push(arr[3]);
         }
         o1.push(a[i]);
        }
      }
     else if(a[i]=='+'||a[i]=='-')
      { 
       if(o1.data[o1.top]=='('||o1.top==-1)
       { 
         o1.push(a[i]);
       }
       else if(a[i]=='+'&&(o1.data[o1.top]=='^'||o1.data[o1.top]=='*'||o1.data[o1.top]=='/'||o1.data[o1.top]=='-'))
       {  
         while(o1.data[o1.top]!='(')
         {
          arr[0]=o2.pop();
          arr[1]=o2.pop();
          arr[2]=o1.pop();
          arr[3]=arr[2]+arr[1]+arr[0];
          o2.push(arr[3]);
         }
         o1.push(a[i]);
       }
       else if(a[i]=='-'&& (o1.data[o1.top]=='^'||o1.data[o1.top]=='*'||o1.data[o1.top]=='/'||o1.data[o1.top]=='+'))
       {
         while(o1.data[o1.top]!='(')
         {
          arr[0]=o2.pop();
          arr[1]=o2.pop();
          arr[2]=o1.pop();
          arr[3]=arr[2]+arr[1]+arr[0];
          o2.push(arr[3]);
         }
         o1.push(a[i]);
       }
      }
      else if(a[i]==')')
      {
      while(o1.data[o1.top]!='(')
      {
          arr[0]=o2.pop();
          arr[1]=o2.pop();
          arr[2]=o1.pop();
          arr[3]=arr[2]+arr[1]+arr[0];
          o2.push(arr[3]);
      }
      o1.pop();
      }
      i++;
    }
    while(o2.top!=-1)
    {
      std::cout<<o2.pop();
    }
}