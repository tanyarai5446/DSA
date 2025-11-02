//singly circular LL add 
#include<iostream>
using namespace std;
#define null 0
struct node
{
    int data;
    node* next;
};
node *first,*temp,*ttemp;
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
void add_before_first(int x)
{
    temp=first;
    
    while(temp->next!=first)
    {
        temp=temp->next;
    }
    ttemp=new node;
    ttemp->data=x;
    temp->next=ttemp;
    ttemp->next=first;
    first=ttemp;
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

void disp()
{   
    temp=first;
    do{
        cout<<temp->data<<"\n";
        temp=temp->next;
    }while(temp!=first);
}
int main()
{   first=ttemp=temp=null;
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
    add_before_first(5);
    disp();
    cout<<"\n";
    del_last();
    disp();
    cout<<"\n";
    del_first();
    disp();
}