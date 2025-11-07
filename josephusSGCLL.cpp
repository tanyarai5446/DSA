#include<iostream>
using namespace std;
struct node
{
    int data;
    node*next;
};
node*first,*temp,*ttemp,*p;
void addnode()
{
    ttemp= new node;
    cin>>ttemp->data;
    ttemp->next=nullptr;
    if(!first)
        {first=temp=ttemp;
        ttemp->next=first;}
    else
        {temp->next=ttemp;
        ttemp->next=first;
    temp=ttemp;}
}
void josephus(node*&head,int n,int k)
{
    temp=first;
    int size;
    for(int i=1;i<n;i++)
    {
       size=1;
       ttemp=temp;
       while(size!=k)
       {
        ttemp=temp;
        temp=temp->next;
        size++;
       }
       ttemp->next=temp->next;
       delete temp;
       temp=ttemp->next;
    }
    temp->next=temp;
    first=temp;
}
void disp()
{
    temp=first;
    do
    {
        cout<<temp->data<<endl;
        temp=temp->next;
    }while(temp!=first);
}
int main()
{
    first=temp=ttemp=nullptr;
    int n;
    cout<<"enter no. of people : ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        addnode();
    }
    cout<<endl;
    disp();
    cout<<endl;
    cout<<"enter step size: ";
    int k;
    cin>>k;
    josephus(first,n,k);
    disp();
    
}