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
void createLoop(node* head, int pos) {
    if (pos == 0) return;
    node* loopNode = head;
    for (int i = 1; i < pos; i++)
        loopNode = loopNode->next;

    node* temp = head;
    while (temp->next)
        temp = temp->next;
        temp->next = loopNode;
}


bool hasLoop(node*head)
{
    node*slow=head;
    node*fast=head;
    while(fast&&fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
    
    if(slow==fast)
    return true;
    }
    return false;

}
void removeLoop(node*head)
{
  node*slow=head;
    node*fast=head;
    while(fast&&fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
    
    if(slow==fast)
    break;
    }
    if(slow!=fast)
    return;
    slow=head;
    while(slow!=fast)
    {
        slow=slow->next;
        fast=fast->next;
    }
    while (fast->next != slow)
        fast = fast->next;

    fast->next = NULL; 
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
    cout << "Enter position to create loop (0 for no loop): ";
    cin >> loopPos;
    createLoop(first, loopPos);

    cout<<"\n";
    if(hasLoop(first))
    {
        cout<<"The given LL has a inner loop\n";
        removeLoop(first);
        cout<<"list after removing loop\n";
        disp();
    }
    else cout<<"The given LL is perfect";
    
}