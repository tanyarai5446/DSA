// stack polish notation conversion postfix to infix
#include<iostream>
#include<string>
#include<cctype>
#include<algorithm>
using namespace std;
struct poin
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
    return "";
    return data[top--];
    }
};
int presi(char c) 
{
  switch(c)
  {
   case '^':return 3;
   case '*':return 2;
   case '/':return 2;
   case '-':return 1;
   case '+':return 1;
   default :return 0;
   }
}

int getlength(char s[])
{
int i=0;
while(s[i]!='\0')
i++;    
return i;
}
int main()
{
 poin z;
 char a[100],i=0,j=0;
 std::string arr[3];
 fgets(a,100,stdin);
 int len=getlength(a)-1;
 z.init(len);
 while(i<len)
 {
     if(isalnum(a[i]))
     {
         z.push(std::string(1,a[i]));
     }
     else if(presi(a[i])>0)
     { 
          arr[0]=z.pop();
          arr[1]=z.pop();
          arr[2]="("+arr[1]+a[i]+arr[0]+")";
          z.push(arr[2]);
     }
     i++;
    }
    
    if (z.top != -1) {
        cout << "Infix expression: " << z.pop() << endl;
    }
 }