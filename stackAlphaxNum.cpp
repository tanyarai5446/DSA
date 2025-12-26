#include<iostream>
using namespace std;
struct AN
{
    char *data;
    int top,size;
    void init(int n)
    {
        size=n;
        data=new char[size];
        top=-1;
    }
    bool isempty()
    {return top==-1;}
    bool isfull()
    {return top==size-1;}
    void push(char c)
    {
        if(isfull())return;
        data[++top]=c;
    }
    char pop()
    {   
        if(isempty())return'\0';
        return data[top--];
    }
};

int getlength(char a[])
{
    int i=0;
    while(a[i]!='\0')
    i++;
    return i;
}

int main()
{  
   AN s,s1,s2,s3;
   char a[100];
   fgets(a,100,stdin);
   int len=getlength(a);
   if(a[len-1]=='\n')
   {
    a[len-1]='\0';
    len--;
   }
   cout<<"original word: ";
   for(int i=0;i<len;i++)
   {
    cout<<a[i];
   }
   cout<<endl;
   s.init(len);s1.init(len);s2.init(len);s3.init(len);
   for(int i=0;i<len;i++)
   s.push(a[i]);
   while(!s.isempty())
   { 
     char c=s.pop();
     if(isalpha(c))s1.push(c);
     else if(isdigit(c))s2.push(c);
     else s3.push(c);
   }
   cout << "Alphabets: ";
   while(!s1.isempty()) cout << s1.pop();
   cout << "\nDigits: ";
   while(!s2.isempty()) cout << s2.pop();
   cout<<"\nrest characters: ";
   while(!s3.isempty()) cout<< s3.pop();
}