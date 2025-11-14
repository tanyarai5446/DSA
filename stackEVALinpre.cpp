//stack evaluation infix to prefix
#include<iostream>
#include<cctype>
#include<string.h>
#include<math.h>
#include<algorithm>
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
        case '+':return o1+o2;
        case '-':return o1-o2;
        case '*':return o1*o2;
        case '/':return o1/o2;
        case '^':return pow(o1,o2);
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
        else{
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
     else if(isdigit(a[i]))
     {
         o2.push(std::string(1,a[i]));
     }
     else if(presi(a[i])>0)
     {   
        while(o1.top!=-1&&o1.data[o1.top]!='('&&shouldpop(o1.data[o1.top],a[i]))
        {
          arr[0]=o2.pop();
          arr[1]=o2.pop();
          arr[2]=o1.pop();
          arr[3]=arr[2]+arr[1]+arr[0];
          o2.push(arr[3]);
        }
         o1.push(a[i]);
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
    while (o1.top != -1) {
    arr[0] = o2.pop();
    arr[1] = o2.pop();
    arr[2] = o1.pop();
    arr[3] = arr[2] + arr[1] + arr[0];
    o2.push(arr[3]);
    }
    std::string s=o2.pop();
    std::cout << "Prefix expression: " << s << std::endl;
    reverse(s.begin(),s.end());
    char expr[100];
    strcpy(expr, s.c_str());  // s.c_str:-convert std::string to char[] raw array or you can say it gives a pointer which points to the raw char array of string, its is used when function accepting char but you have string 
    int leng = getlength(expr);  // or use s.length()
    int result = post(expr, leng);
    
    std::cout << "Evaluated result: " << result << std::endl;

}