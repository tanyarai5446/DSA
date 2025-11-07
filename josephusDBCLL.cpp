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
void josephus(node*&head,int n,int k)
{
  temp =head;
  int size;
  for(int i=1;i<n;i++)
  {
    size=1;
    while(size!=k)
    {
        temp=temp->next;
        size++;
    }
    p=temp->next;
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    delete temp;
    temp=p;
  }
  temp->next=temp;
  head = temp;
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
    cout<<"enter step size: ";
    int k;
    cin>>k;
    josephus(first,n,k);
    disp();
}