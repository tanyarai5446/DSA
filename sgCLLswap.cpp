//singly circular LL swapping
#include<iostream>
using namespace std;
#define null 0
#include<iostream>
using namespace std;
#define null 0
struct node
{
    int data;
    node* next;
};
node *first,*temp,*ttemp,*p,*q,*r,*prevM,*prevN,*currN,*currM;
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
void swapFS()
{
 p=first->next;
 temp=first;
 while(temp->next!=first)
 {
    temp=temp->next;
 }
 q=p->next;
 p->next=first;
 first->next=q;
 temp->next=p;
 first=p;
}
void swapFL()
{
   temp=first;
   p=first->next;
   while(temp->next !=first)
   {
    ttemp=temp;
    temp=temp->next;
   }
   ttemp->next=first;
   first->next=temp;
   temp->next=p;
   first=temp;
}
void swapL2L()
{
    temp=first;
    while(temp->next->next!=first)
    {
        ttemp=temp;temp=temp->next;
    }
    p=temp->next;
    ttemp->next=p;
    p->next=temp;
    temp->next=first;
}
void swapMN(node*head,int m,int n)
{
    if(!head){
        cout<<"list is empty.Swap not performed\n9";
        return;}
    if(m==n) {
        cout<<"positions are same .no swap needed\n";
        return;}//if list empty or x==y 
    if(m>n)swap(m,n);
    prevM=null;    currM=head;
    prevN=null;    currN=head;
    int count=1;
    while(count!=m){
        prevM=currM;
        currM=currM->next;
        count++;
        if(currM==head) {cout<<"m not found\n";return;}//m out of bound
    }
    count=1;
    while(count!=n)
    {
        prevN=currN;
        currN=currN->next;
        count++;
        if(currN==head) {cout<<"n not found\n";return;}//n out of bound
    }
    //adjacent case
    if(currM->next==currN)
    {
        if(prevM)prevM->next=currN;
        else
        head=currN;
        currM->next=currN->next;
        currN->next=currM;
    }
    //default case
    else{
        if(prevM)prevM->next=currN;
        if(prevN)prevN->next=currM;
        temp=currM->next;
        currM->next=currN->next;
        currN->next=temp;
        //update head if needed
        if(currM==head)head=currN;
        else if(currN==head)head=currM;
    }
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
    // cout<<"\n";
    // swapFS();
    // disp();
    // cout<<"\n";
    // swapFL();
    // disp();
    // cout<<"\n";
    // swapL2L();
    // disp();
    cout<<"\n";
    swapMN(first,4,7);
    disp();
}