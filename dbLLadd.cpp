//add functions
#include<iostream>
using namespace std;
#define null 0
struct node
{
    int data;
    node *prev,*next;
};
node*first,*temp,*ttemp,*p;

void addnode()
{
    ttemp=new node;
    cin>>ttemp->data;
    ttemp->next=ttemp->prev=null;
    if(first==null)
    first=ttemp;
    else{
    temp->next=ttemp;
    ttemp->prev=temp;}
    temp=ttemp;
}

void add_before_first()
{

 p=new node;

 cin>>p->data;

 p->next=first;

 p->prev=null;

 first->prev=p;

 first=p;


}

void add_before_given(int x)
{
 temp=first;
 while(temp->data!=x)
 {
   temp=temp->next;
 }
 p=new node;
 cin>>p->data;
 p->next=temp;
 p->prev=temp->prev;
 temp->prev->next=p;
 temp->prev=p;
}

void add_after_given(int y)
{
 temp = first;
 while(temp->data!=y)
 {
 temp=temp->next;
 }
 p=new node;
 cin>>p->data;
 p->prev=temp;
 p->next=temp->next;
 temp->next=p;
 temp->next->prev=p;
}

void disp()
{

  temp=first;
  while(temp!=null)
  {
    cout<<temp->data<<endl;
    temp=temp->next;
  }
}
int main()
{
  first=temp=ttemp=null;
  int n;cin>>n;
  for(int i=0;i<n;i++)
  {
    addnode();
  }
  cout<<"\n";

  disp();
  add_before_first();
  disp();
  add_before_given(3);
  disp();
  add_after_given(5);
  disp();
}