//deletion
#include<stdlib.h>
#include<iostream>
#define null 0
using namespace std;

 struct node
{
  int data;
    node *next;
};
node *first,*temp,*ttemp,*p,*q,*r,*ptemp,*pttemp,
*ntemp,*nttemp;

void init()
{
 first=temp=ttemp=null;
}
void addnode(int val)
{
  temp=first;
  while(temp->next!=null)
  {
  temp=temp->next;

  }
  ttemp=new node;
  ttemp->data=val;
  ttemp->next=null;
  temp->next=ttemp;
}
void createfirst(int val)
{
 first=new node;
  first->data=val;
  first->next=null;
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
void deletion()
{
    temp=first;
    first=first->next;
    temp->next = null;
    delete temp;
}
void del_after(int x)
{
    temp=first;
    while(temp->data!=x)
    {
        temp=temp->next;
    }
    ttemp=temp->next;
    p=ttemp->next;
    temp->next=p;
    ttemp->next=null;
    delete ttemp;
}
 
/*void del_before(int y)
{
    temp=first;
    while(temp->next->data!=y)
    {
        ttemp=temp;
        temp=temp->next;
    }
    p=temp->next;
    ttemp->next=p;
    temp->next=null;
    delete temp;
}*/
void del_before(int y)
{
    // Edge case: list is empty or has only one node
    if (first == null || first->next == null) return;

    // Edge case: y is at head — no node before it
    if (first->data == y) return;

    temp = first;
    ttemp = null;

    // Traverse to find node before the one with data y
    while (temp->next != null && temp->next->data != y)
    {
        ttemp = temp;
        temp = temp->next;
    }

    // If y not found, or y is at head, return
    if (temp->next == null) return;

    // Now temp is the node before y
    if (ttemp == null)
    {
        // We're deleting the head
        first = temp->next;
    }
    else
    {
        ttemp->next = temp->next;
    }

    delete temp;
}
void del_last()
{
  temp=first;
  while(temp->next!=null)
  { 
    ttemp=temp;
    temp=temp->next;
  }
  ttemp->next=null;
  delete temp;
  
}
int main()
{
	init();
	createfirst(10);
	addnode(20);
	addnode(30);
	addnode(40);
	addnode(50);
    disp();
    cout<<"\n";
    deletion();
    disp();
    cout<<"\n";
    del_after(30);
    disp();
    cout<<"\n";
    del_before(30);
    disp();
    cout<<"\n";
    del_last();
    disp();

}
