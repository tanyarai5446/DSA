#include<iostream>
#include<string>
using namespace std;
struct str
{
    char *data;
    int top;
    str(int s)
    {
        data = new char[s];
    }
};
int getLength(char s[])
{
    int i=0;
    while(s[i]!='\0')
    {
        i++;
    }
    return i;
}
str *p;
void init()
{
    p->top=-1;
}
void strpal(char s[],int len)
{   
    int i=0;
    int ispal=1;
    while(i<len&&p->top!=-1)
    {
        if(p->data[p->top--]!=s[i])
        {ispal=0;
        break;}
        i++;
    }
    if(ispal)
    cout<<s<<" is palindrome string";
    else
    cout<<s<<" is not palindrome string";
}
int main()
{   
    char word[100];
    cout<<"enter a word: ";
    fgets(word,100,stdin);
    int len=getLength(word);
    if (word[len - 1] == '\n') 
    {
        word[len - 1] = '\0';
        len--;
    }
    p=new str(len);
    init();
    //pushing char into stack
    for(int i=0;i<len;i++)
    p->data[++p->top]=word[i];
    strpal(word,len);
    delete p;
}