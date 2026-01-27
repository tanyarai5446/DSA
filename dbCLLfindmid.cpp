//finding mid node in db CLL 
//if even no. of elements  then second mid
//if odd then mid only
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
  {
    first=ttemp;
    ttemp->next=ttemp->prev=first;
  }
  else
  {
    temp->next=ttemp;
    ttemp->prev=temp;
    ttemp->next=first;
    first->prev=ttemp;
  }
  temp=ttemp;
}
void findMid()
{
  temp=first;
  int mid;
  int count=1;
  while(temp->next!=first)
  {
    temp=temp->next;
    count++;
  }
  mid=(count/2);
  ttemp=first;
  int found=1;
  while(found<=mid)
  {
    ttemp=ttemp->next;
    found++;
  }
  cout<<"mid element is "<<ttemp->data;
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
    findMid();  
}