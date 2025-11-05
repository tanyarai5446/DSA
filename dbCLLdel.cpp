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
    ttemp->next=ttemp->prev=ttemp;
    temp=ttemp;}
    else{
       temp->next=ttemp;
       ttemp->prev=temp;
       ttemp->next=first;
       first->prev=ttemp;
       temp=ttemp;
    }
    

}
void delfirst()
{
  temp=first->prev;
  ttemp=first->next;
  first->next=first->prev=nullptr;
  ttemp->prev=temp;
  temp->next=ttemp;
  delete first;
  first=ttemp;
}
void dellast()
{
  temp=first->prev;
  ttemp=temp->prev;
  ttemp->next=first;
  first->prev=ttemp;
  delete temp;

}


void del_before_given(int y) {
    if (first == nullptr || first->next == first) return;

    temp = first;
    bool found = false;
    do {
        if (temp->next->data == y) {
            found = true;
            break;
        }
        temp = temp->next;
    } while (temp != first);

    if (!found) {
        cout << "Value " << y << " not found in list.\n";
        return;
    }

    node* toDelete = temp;
    node* before = toDelete->prev;
    node* after = toDelete->next;

    before->next = after;
    after->prev = before;

    if (toDelete == first) {
        first = after;
    }

    delete toDelete;
}

void del_after_given(int x)
{
    if (first == nullptr) return;
    temp = first;
    bool found = false;
    do {
        if (temp->data == x) {
            found = true;
            break;
        }
        temp = temp->next;
    } while (temp != first);

    if (!found || temp->next == first) return;

    ttemp = temp->next;
    p = ttemp->next;
    temp->next = p;
    p->prev = temp;
    delete ttemp;
}
void delanynth(int n)
{
 if(first==nullptr)return;//if list empty
  temp=first;
  int count =1;
  bool found=false;
while (count < n && temp->next != first) {
    temp = temp->next;
    count++;
}
if (count == n) {
    found = true;
    cout<<"nth node found\n";
    // temp is the n-th node
} else {
    found = false;
    cout<<"nth node not found\n";
    return;
    // temp is the last node before looping
}
node*todelete=temp;
node*after=todelete->next;
node*before=todelete->prev;
if(todelete==first)
{
    first=after;
    after->prev=before;
    before->next=after;
}
else if(todelete==first->prev)
{
    before->next=first;
    first->prev=before;
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
    delanynth(6);
    // delfirst();
    // disp();
    // cout<<"\n";
    // dellast();
    // disp();
    // cout<<"\n";
    // del_after_given(4);
    // disp();
    // cout<<"\n";
    // del_before_given(3);
    disp();
    cout<<"\n";
}
