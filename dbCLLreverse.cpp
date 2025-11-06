#include<iostream>
using namespace std;
struct node
{
    int data;
    node*prev,*next;

};
node *first,*temp,*ttemp,*p;
void addnode()
{
    ttemp=new node;
    ttemp->next=ttemp->prev=nullptr;
    cin>>ttemp->data;
    if(first==nullptr)
    {first=ttemp;
    ttemp->next=ttemp->prev=first;}
    else{
       temp->next=ttemp;
       ttemp->prev=temp;
       ttemp->next=first;
       first->prev=ttemp;
    }
    temp=ttemp;

}
void reverse()
{
    temp=first;
    ttemp=nullptr;
    node *next=nullptr;
    do{
        next=temp->next;
        temp->prev=next;
        temp->next=ttemp;
        ttemp=temp;
        temp=next;
    }while(temp!=first);
    first->next=ttemp;
    first=ttemp;
    
}
void disp()
{
    temp=first;
    do
    {
        cout<<temp->data<<"\n";
        temp=temp->next;
    }while(temp!=first);

}

int main()
{
    first=temp=ttemp=nullptr;
    int n;
    cout<<"enter n: ";
    cin>>n;
    for(int i=0;i<n;i++)
    addnode();
    cout<<"\n";
    disp();
    cout<<"\n";
    reverse();
    disp();
    cout<<"\n";
}