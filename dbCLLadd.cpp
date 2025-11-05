//dbCLL add functions
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
void add_after_first(int x)
{
    temp=first->next;
    ttemp=new node;
    ttemp->data=x;
    ttemp->prev=first;
    ttemp->next=temp;
    temp->prev=ttemp;
    first->next=ttemp;
}
void add_before_first(int y)
{
    temp=first->prev;
    ttemp=new node;
    ttemp->data=y;
    ttemp->next=first;
    first->prev=ttemp;
    ttemp->prev=temp;
    temp->next=ttemp;
    first=ttemp;
}
void add_after_given(int x,int y)
{
    temp=first;
    while(temp->data!=x)
    {
        temp=temp->next;
    }
    p=temp->next;
    ttemp=new node;
    ttemp->data=y;
    ttemp->prev=temp;
    temp->next=ttemp;
    ttemp->next=p;
    p->prev=ttemp;
}
void add_before_given(int x,int y)
{
  temp=first;
  while(temp->data!=x)
  {
    temp=temp->next;
  }
  p=temp->prev;
  ttemp=new node;
  ttemp->data=y;
  ttemp->next=temp;
  temp->prev=ttemp;
  p->next=ttemp;
  ttemp->prev=p;
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
    add_after_first(0);
    disp();
    cout<<"\n";
    add_before_first(0);
    disp();
    cout<<"\n";
    add_after_given(3,4);
    disp();
    cout<<"\n";
    add_before_given(3,6);
    disp();
    cout<<"\n";
}