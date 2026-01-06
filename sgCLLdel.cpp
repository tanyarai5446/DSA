#include<iostream>
using namespace std;
#define null 0
struct node
{
    int data;
    node* next;
};
node *first,*temp,*ttemp,*p,*q;
void addnode()
{  
   ttemp=new node;
   cin>>ttemp->data;
   ttemp->next=first;//default 
   if(first==null){
   first=temp=ttemp;
   ttemp->next=first;}//circular ink
   else{
   temp->next=ttemp;
   ttemp->next=first;
   temp=ttemp;}
}
void del_last()
{
    temp=first;
    while(temp->next!=first)
    {   
        ttemp=temp;
        temp=temp->next;
    }
    ttemp->next=first;
    temp->next=null;
    delete temp;
    
}
void del_first()
{   ttemp=first;
    temp=first->next;
    while(ttemp->next!=first)
{
    ttemp=ttemp->next;
}
    ttemp->next=temp;
    first->next=null;
    first=temp;
}
void delanyMth(int m)
{ 
  if(first==null)return;
  temp=first;
  ttemp=first;
  int count=1;
  bool found=false;
  while(count<m&&temp->next!=first)
  { ttemp=temp;
    temp=temp->next;
    count++;
  }
  if(count==m)
  {
    found=true;
    cout<<"node found\n";
  }
  else 
  {
    found=false;
    cout<<"node not found\n";
    return;
  }
  p=first;
  while(p->next!=first)
  p=p->next;
  node*todelete=temp;
  node*after=todelete->next;
  if(todelete==first)
  {
    first=after;
    p->next=after;
  }
  else if(todelete==p)
  {
    ttemp->next=first;
  }
  else
  {
    ttemp->next=temp->next;
  } 
  delete temp;
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
    first=ttemp=temp=null;
    int n;
    cout<<"enter no. of terms in LL: ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
      addnode();
    }
    cout<<"\n";
    disp();
    cout<<"\n";
    del_last();
    disp();
    cout<<"\n";
    del_first();
    disp();
    cout<<"\n";
    delanyMth(1);
    disp();
    cout<<"\n";

}