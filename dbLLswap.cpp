//swappping in doubly LL
#include<iostream>
using namespace std;
#define null 0
struct node
{
    int data;
    node *prev,*next;
};
node*first,*temp,*ttemp,*p,*nodeM,*nodeN,*nextN,*prevM;

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
void swapfs()

{

 temp=first->next;

 ttemp=temp->next;

 first->prev=temp;

first->next=ttemp;
 temp->prev=null;

temp->next=first;
first = temp;
}

void swapl2l()
{

 temp=first;

 while(temp->next!=null)

 temp=temp->next;

 ttemp=temp->prev;

 temp->next=ttemp;

 temp->prev=ttemp->prev;

 ttemp->next=null;

 ttemp->prev=temp;

 temp->prev->next=temp;
}

void swapMN(node*&head,int m,int n)
{
  if(!head)
  {
    cout<<"list is empty\n";
    return;
  }
if(m==n)
{
    cout<<"swap not possible\n";
    return;
}
if(m>n)swap(m,n);
nodeM=head;   nodeN=head;
for(int i=1;i<m;i++)nodeM=nodeM->next;
for(int i=1;i<n;i++)nodeN=nodeN->next;
if(!nodeM||!nodeN)return;
if(nodeM->next==nodeN){
    prevM=nodeM->prev;
    nextN=nodeN->next;
    if(prevM)prevM->next=nodeN;
    if(nextN)nextN->prev=nodeM;
    nodeN->prev = prevM;
    nodeN->next = nodeM;
    nodeM->prev = nodeN;
    nodeM->next = nextN;
    if (head == nodeM) head = nodeN;

}
else{
// Swap prev pointers
    if (nodeM->prev) nodeM->prev->next = nodeN;
    if (nodeN->prev) nodeN->prev->next = nodeM;

    // Swap next pointers
    if (nodeM->next) nodeM->next->prev = nodeN;
    if (nodeN->next) nodeN->next->prev = nodeM;

    // Swap nodeM and nodeN's own pointers
    swap(nodeM->prev, nodeN->prev);
    swap(nodeM->next, nodeN->next);

    // Update head if needed
    if (head == nodeM) head = nodeN;
    else if (head == nodeN) head = nodeM;
}

}
void disp(node*head)

{

temp=head;

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

disp(first);
cout<<"\n";
swapfs();
disp(first);
cout<<"\n";
swapl2l();
disp(first);
cout<<"\n";
swapMN(first,1,5);
disp(first);

}