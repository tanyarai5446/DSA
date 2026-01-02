#include<iostream>
using namespace std;
struct Lstack
{
    int data;
    Lstack *next;
};
Lstack *top,*temp,*ttemp;

void init()
{
    top=temp=ttemp=nullptr;
}
void push(int x)
{
    temp=new Lstack;
    if(temp==nullptr)return;
    temp->data=x;
    temp->next=top;
    top=temp;
}

int pop()
{
    int y;
    if(top==nullptr)return 0;
    y=top->data;
    temp=top;
    top=top->next;
    temp->next=nullptr;
    delete temp;
    return y;
}
int main()
{
    init();
    push(10);
    push(20);
    push(30);
    push(40);
    cout<<"popped elements are: \n";
    cout<<pop()<<endl;
    cout<<pop()<<endl;
    cout<<pop();
}