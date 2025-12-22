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
void delfirst()
{
  temp=first->next;
  temp->prev=nullptr;
  delete first;
  first=temp;
  
}
void dellast()
{
  temp=first;
  while(temp->next!=nullptr)
  {
    temp=temp->next;
  }
  ttemp=temp->prev;
  ttemp->next=nullptr;
  delete temp;
}
void delanymth(int m)
{
  if(first==nullptr)return;
  temp=first;
  int count=1;
  bool found=false;
  while(count<m&&temp->next!=null)
  {temp=temp->next;
  count++;}
  if(count==m)
  {
    found=true;
    cout<<m<<"th node found\n";
  }
  else{
    found=false;
    cout<<m<<"th node not found\n";
    return;
  }
  node*todelete=temp;
  node*after=todelete->next;
  node*before=todelete->prev;
  if (before==nullptr)
  {
    first=after;
    after->prev==nullptr;
  }else if(after==nullptr)
  {
    before->next=nullptr;
  }
  else{
    before->next=after;
    after->prev=before;
  }
  delete todelete;
  
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
cout<<"\n";
delfirst();
disp();
cout<<"\n";

dellast();
disp();
cout<<"\n";

delanymth(3);
disp();


}
