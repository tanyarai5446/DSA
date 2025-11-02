//LLc of names and sort it in alphabetical order
#include<iostream>
#include<string>
using namespace std;
#define null 0
struct dict
{
    string data;
    dict *next;

};
dict *first,*temp,*ttemp,*i,*j;
void init()
{first=temp=ttemp=null;}
void addnode()
{
    ttemp=new dict;
    cin>>ttemp->data;
    ttemp->next=null;
    if(first==null)
    first=ttemp;
    else
    temp->next=ttemp;
    temp=ttemp;
}
void disp()
{
    temp=first;
    while(temp!=null)
    {
        cout<<temp->data<<"\n";
        temp=temp->next;
    }
}
void inorder()
{   
    string tempdata;
    for(i=first;i!=null;i=i->next)
    {
        for(j=i->next;j!=null;j=j->next)
        {
            if(i->data>j->data)
            {
              //swap
              tempdata=i->data;
              i->data=j->data;
              j->data=tempdata;
            }
        }
    }

}
int main()
{
    init();
    int n;
    cout<<"enter number of names u want to enter: ";
    cin>>n;
    for(int i=1;i<=n;i++)
    {   
        addnode();
    
    }
    cout<<"\noriginal sequence\n";
    disp();
    cout<<"\n";
    inorder();
    disp();
}