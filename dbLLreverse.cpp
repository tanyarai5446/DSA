//reverse=ing doublyLL
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
void reverse()
{
    ttemp=null;
    while(first!=null)
    {
        temp=first;
        first->prev=first->next;
        first=first->next;
        temp->next=ttemp;
        ttemp=temp;

    }
    first=ttemp;
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
reverse();
disp(first);


}