#include<iostream>
using namespace std;
struct stack
{
    char *s;
    int top;
    int size;
    void init(int n)
    {
        size=n;
        s=new char[size];
        top=-1;
    }
    void push(char x)
    {
        if(top==size-1)return;
        s[++top]=x;
    }
    char pop()
    {
        if(top==-1)return'\0';
        return s[top--];
    }

};
bool isnotalpha(char c)
{return !((c>='A'&&c<='Z')||(c>='a'&&c<='z'));}//return (!true)=false if c is alpha and (!false)=ture if c is not alpha
void nonalphacheck(stack &s1)
{ 
   bool found =false;
    while(s1.top!=-1)
   { 
    char c=s1.pop();
    if(isnotalpha(c)){
    cout<<"Non-alphabetical character found: '" << c << "'\n";
    found = true;}
   }
   if(!found)
   cout<<"all characters are alphabetical";
}
int getLength(char a[])
{
    int i=0;
    while(a[i]!='\0')
    i++;
    return i;
}
int main()
{
  char a[100];
  fgets(a,100,stdin);
  int len=getLength(a);
  if (a[len - 1] == '\n') {
    a[len - 1] = '\0';
    len--;
}
  stack s1;
  s1.init(len);
  for(int i=0;i<len;i++)
  {
    s1.push(a[i]);
  }
  nonalphacheck(s1);

}