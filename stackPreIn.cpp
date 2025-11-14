//stack prefix to infix
#include<iostream>
#include<cctype>
#include<string>
#include <algorithm>
using namespace std;
struct inpo
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
int main()
{
 inpo z;
 std::string a;
 std::cin >> a;  // Reads until space or newline
 std::reverse(a.begin(),a.end());
 int len=a.length();
 z.init(len);
 std::string s[4];
 int i=0;
 while(i<len)
{
  if(isalnum(a[i]))
  {
    z.push(std::string(1,a[i]));
  }
  else if(presi(a[i])>0)
  {
    s[0]=z.pop();
    s[1]=z.pop();
    s[2]=a[i];
    s[3] = "(" + s[0] + s[2] + s[1] + ")";
    z.push(s[3]);
  }
  i++;
}
if (z.top != -1)
std::cout<<z.pop();
}