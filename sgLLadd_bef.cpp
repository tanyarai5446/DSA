#include<stdio.h>
#include<conio.h>
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
void add_before_first()
{
    temp = new node;
    cin>>temp->data;
    temp->next=first;
    first=temp;
}
void add_before_given(int x,int y)
{
    temp=first;
    while(temp->data!=x)
    {
        ttemp=temp;
        temp=temp->next;
    }
    p=new node;
    cin>>p->data;
    p->next=temp;
    ttemp->next=p;
}
void add_before_last()
{
    temp=first;
    while(temp->next!=null)
    {
        ttemp=temp;
        temp=temp->next;
    }
    q=new node;
    cin>>q->data;
    q->next=temp;
    ttemp->next=q;
}

int main()
{
	init();
	createfirst(10);
	addnode(20);
	addnode(30);
	addnode(50);
	addnode(60);
	disp();
    add_before_first();
    disp();
    add_before_given(30,90);
    disp();
    add_before_last();
    disp();

}
