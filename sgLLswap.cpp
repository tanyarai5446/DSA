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
node *first,*temp,*ttemp,*p,*q,*r,*s,*ptemp,*pttemp,
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
void swapFS()
{
  temp=first->next;
  first->next=temp->next;
  temp->next=first;
  first=temp;
}
void swapMN(int x,int y)
{
 if(x==y) return;

 // Ensure x comes before y in the list
  if (x > y) 
  {
    int tempVal = x;
    x = y;
    y = tempVal;
  }
 temp=first;
 ttemp=first;
 p=q=null;
 while(temp!=null&&temp->data!=x)
 {
    p=temp;
    temp=temp->next;
 }
 while(ttemp!=null&&ttemp->data!=y)
 {
    q=ttemp;
    ttemp=ttemp->next;
 }
 if(temp==null || ttemp==null) return;//if x or y not found
 //check temp and ttemp if adjacent
 if(temp->next==ttemp)
 {
        //x before y
        r=ttemp->next;
        //if x is not head
        if(p!=null)
            p->next=ttemp;
        else
            first=ttemp;

        ttemp->next=temp;
        temp->next=r;
 }
 else
 {
        //non adjacent case
        r = temp->next;
        s = ttemp->next;

        if (p != null)
            p->next = ttemp;
        else
            first = ttemp;

        if (q != null)
            q->next = temp;
        else
            first = temp;
        temp->next=s;
        ttemp->next=r;
 }
}
void swapL2L()
{
  temp=first;
  while(temp->next->next!=null)
  { 
    ttemp=temp;
    temp=temp->next;
  }
  ttemp->next=temp->next;
  temp->next->next=temp;
  temp->next=null;
}
int main()
{
	init();
	createfirst(10);
	addnode(20);
	addnode(30);
	addnode(40);
	addnode(50);
    cout<<"/n";
	  disp();
    cout<<"\n";
    swapFS();
    disp();
    cout<<"\n";
    swapMN(40,20);
    disp();
    cout<<"\n";
    swapL2L();
    disp();
}