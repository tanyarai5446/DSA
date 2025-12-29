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
void swapFS()
{
 temp=first->prev;
 ttemp=first->next;
 p=ttemp->next;
 ttemp->prev=temp;
 ttemp->next=first;
 first->prev=ttemp;
 first->next=p;
 p->prev=first;
 temp->next=ttemp;
 first=ttemp;
}
void swapL2L()
{
    temp=first->prev;
    ttemp=temp->prev;
    p=ttemp->prev;
    p->next=temp;
    temp->prev=p;
    temp->next=ttemp;
    ttemp->prev=temp;
    ttemp->next=first;
    first->prev=ttemp;
}
void swapFL()
{
 temp=first->prev;
 ttemp=temp->prev;
 p=first->next;
 ttemp->next=first;
 first->prev=ttemp;
 first->next=temp;
 temp->prev=first;
 temp->next=p;
 p->prev=temp;
 first=temp;
}
void swapMN(node*&head,int m,int n)
{
 if(!head||(head->next==head&&head->prev==head)) return;
 if(m==n)return;
 if(m>n)swap(m,n);
 node*mnode=head;
 node*nnode=head;
 int count = 1;
 node* temp = head;
 while (temp->next != head) 
 {
    count++;
    temp = temp->next;
 }
 if (m > count || n > count) 
 {
    cout << "Invalid positions: m or n out of bounds\n";
    return;
 }
 //find mth and nth  node
 for(int i=1;i<m;i++)mnode=mnode->next;
 for(int i=1;i<n;i++)nnode=nnode->next;
//adjacent cases     
 if(mnode->next==nnode)
   {  
    node*mbefore=mnode->prev;
    node*nafter=nnode->next;

    mbefore->next=nnode;
    nnode->prev=mbefore;

    nnode->next-mnode;
    mnode->prev=nnode;

    mnode->next=nafter;
    nafter->prev=mnode;
    
    if(mnode==head)head=nnode;
   }
 else
   {
    node* mbefore = mnode->prev;
    node* mafter = mnode->next;
    node* nbefore = nnode->prev;
    node* nafter = nnode->next;

    mbefore->next=nnode;
    nbefore->next=mnode;

    mafter->prev=nnode;
    nafter->prev=mnode;

    swap(mnode->next,nnode->next);
    swap(mnode->prev,nnode->prev);

    if(mnode==head)head=nnode;
    else if(nnode==head)head=mnode;
   }
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
    swapFS();
    disp();
    cout<<"\n";
    swapL2L();
    disp();
    cout<<"\n";
    swapFL();
    disp();
    cout<<"\n";
    swapMN(first,3,5);
    disp();
    cout<<"\n";
}