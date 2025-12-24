//input a string and store it in LL and then through LL check if its palindrome or not
#include<iostream>
#include<string>
#define null 0
using namespace std; 
struct palstr
{
    char data;
    palstr *next;
};
palstr *first,*temp,*ttemp,*p,*revfirst,*revtemp,*rev,*orig;
void init()
{
    first=temp=ttemp=null;
}
void addnode(char name)
{ 
    ttemp=new palstr;
    ttemp->data=name;
    ttemp->next=null;
    if(first==null)
    first=ttemp;
    else
    temp->next=ttemp;

    temp=ttemp;

}
void disp(palstr* head)
{
    temp=head;
    while(temp!=null)
    {
        cout<<temp->data<<"\n";
        temp=temp->next;
    }
}
void stringLL(string name,int l)
{ 
 init();
 for(int i=0;i<l;i++)
 {
    addnode(name[i]);
 }
}
palstr* reversedLL(palstr* head)
{   
    revfirst=null;
    while(head!=null)
    {  
       revtemp=new palstr;
       revtemp->data=head->data;
       revtemp->next=revfirst;
       revfirst=revtemp;
       head=head->next;   
    }
    return revfirst;
    
}
void ispal()
{
    rev=reversedLL(first);
    orig=first;
    bool ispal=true;
    while(orig!=null&rev!=null)
    {
        if(orig->data!=rev->data)
        {
            ispal=false;
            break;
        }
        orig=orig->next;
        rev=rev->next;
    }
    if( ispal)
    cout<<"palindrome\n";
    else
    cout<<"not a palindrome\n";
}
int main()
{ init();
  string  name ="star";
  int l=name.length();
  stringLL(name,l);
  disp(first);
  reversedLL(first);
  cout<<"\n";
  disp(revfirst);
  ispal();
}
