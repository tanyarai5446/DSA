#include<iostream>
using namespace std;
struct node
{
    int data;
    node*next;
};
node*first,*temp,*ttemp,*p;
void addnodesortedly()
{
  ttemp=new node;
  cin>>ttemp->data;
  ttemp->next=nullptr;
  if(!first)
  {
    first=ttemp;
    return;
  }
  if(ttemp->data>first->data)
  {
    ttemp->next=first;
    first=ttemp;
    return;
  }
  temp=first;
  while(temp->next && temp->next->data>ttemp->data)
  {
    temp=temp->next;
  }
  ttemp->next=temp->next;
  temp->next=ttemp;

}
void disp()
{
    temp=first;
    while(temp!=nullptr)
    {
        cout<<temp->data<<endl;
        temp=temp->next;
    }
}
int main()
{
    first=temp=ttemp=nullptr;
    int n;
    cout<<"enter number of elements in LL: ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        addnodesortedly();
    }
    cout<<"sorted LL\n";
    disp();
}