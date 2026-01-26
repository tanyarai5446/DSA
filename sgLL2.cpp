//LL of natural no. divided into 2 separate even and odd LL
#include<iostream>
#define null 0
using namespace std;
 struct NatNo
{
  int data;
    NatNo *next;
};
NatNo *first,*temp,*ttemp,*p,*q,*r,*ptemp,*pttemp,
*ntemp,*nttemp,*efirst=null,*ofirst=null,*etemp=null,*otemp=null;

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
  ttemp=new NatNo;
  ttemp->data=val;
  ttemp->next=null;
  temp->next=ttemp;
}
void createfirst(int val)
{
  first=new NatNo;
  first->data=val;
  first->next=null;
}
void disp(NatNo* head)
{
 temp=head;
 while(temp!=null)
 {
   cout<<temp->data<<endl;
   temp=temp->next;
 }
}
NatNo* createP(int x)
{
    p=new NatNo;
    p->data=x;
    p->next=null;
    return p;
}
void even_part()
{
  temp=first;
  while(temp!=null)
  {
    if(temp->data%2==0)
    {
     ntemp=createP(temp->data); 
     if(efirst==null)
     {
        efirst=ntemp;
        etemp=efirst;
     }
     else
     {
        etemp->next=ntemp;
        etemp=etemp->next;
     }
    }
    temp=temp->next;
  }
}
void odd_part()
{
  temp= first;
  while(temp!=null)
  {
    if(temp->data%2!=0)
    {
        ptemp=createP(temp->data);
        if(ofirst==null)
        {
            ofirst=ptemp;
            otemp=ofirst;
        }
        else
        {
            otemp->next=ptemp;
            otemp=otemp->next;
        }
    }
    temp=temp->next;
  }
}
int main()
{
    init();
    createfirst(1);
    int i=2;
    while(i<=10)
    {
    addnode(i);
    i++;
    }
    disp(first);
    cout<<"\n";
    even_part();
    disp(efirst);
    cout<<"\n";
    odd_part();
    disp(ofirst);
}
