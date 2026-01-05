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
   if(first==null)
   {
   first=temp=ttemp;
   ttemp->next=first;
   }//circular ink
   else
   {
   temp->next=ttemp;
   ttemp->next=first;
   temp=ttemp;
   }
}
void reverse()
{
  temp=first;
  ttemp=null;
  node *next=null;
  do{
     next=temp->next;
     temp->next=ttemp;
     ttemp=temp;
     temp=next;
  }while(temp!=first);
  first->next=ttemp;
  first=ttemp;
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
    reverse();
    disp();
}