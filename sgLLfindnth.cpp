//Find the Nth node from the end of a singly linked list in one traversal
#include<iostream>
#include<string>
using namespace std;
#define null 0
struct node
{
    string data;
    node *next;

};
node *first,*temp,*ttemp,*i,*j;
void init()
{first=temp=ttemp=null;}
void addnode()
{
    ttemp=new node;
    cin>>ttemp->data;
    ttemp->next=null;
    if(first==null)
    first=ttemp;
    else
    temp->next=ttemp;
    temp=ttemp;
}
void disp()
{
    temp=first;
    while(temp!=null)
    {
        cout<<temp->data<<"\n";
        temp=temp->next;
    }
}
node*findingNth_from_last(node*head,int N)
{
   node*p=head;
   node*q=head;
   for(int i=0;i<N;i++)
   {
    p=p->next;
   }
   while(p)
   {
    p=p->next;
    q=q->next;
   }
  return q;
}
int main()
{
    init();
    int n,loopPos;
    cout<<"enter number of names u want to enter: ";
    cin>>n;
    for(int i=1;i<=n;i++)
    {   
        addnode();
    
    }
    cout<<"\noriginal sequence\n";
    disp();
    int N;
    cout<<"enter the position of node: ";
    cin>>N;
    node*val=findingNth_from_last(first,N);
    if (val)
        cout << "Nth node from end is: " << val->data << endl;
    else
        cout << "Invalid N — exceeds list length.\n";


}