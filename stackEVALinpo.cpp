// stack polish notation conversion infix to postfix
#include<iostream>
#include<cctype>
#include<math.h>
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
struct intstack
{
   int *data;
   int top,size;
   void init(int n)
   {
   size=n;
   data=new int[size];
   top=-1;
   }
   void push(int c)
   {
    if(top==size-1)
    return;
    data[++top]=c;
   }
   int pop()
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
int calc(int o1,int o2,char x)
{
    switch(x)
    {
        case '+':return o2+o1;
        case '-':return o2-o1;
        case '*':return o2*o1;
        case '/':return o2/o1;
        case '^':return pow(o2,o1);
        default:return -1;
    }
}
int post(char post[],int l)
{
    int i;
    int op1,op2,R;
    intstack s;
    s.init(l);
    for(i=0;i<l;i++)
    {
        if(isalnum(post[i]))
        s.push(post[i]-'0');
        else
        {
            op1=s.pop();
            op2=s.pop();
            R=calc(op1,op2,post[i]);
            s.push(R);
        }
    }
    return s.pop();
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
     else if(isdigit(a[i]))
     {
         str[j++]=a[i];
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
    int result =post(str,leng);
   
    cout << "Postfix expression: " << str << endl;
    cout << "Evaluated result: " << result << endl;
    delete[] z.data;
 }