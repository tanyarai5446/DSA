#include<iostream>
using namespace std;
#define max 7
struct CLLstack
{
    int data;
    CLLstack*next;
};
CLLstack *temp,*ttemp;
int stack[max];
int top=-1;
bool isfull()
{
 return top==max-1;
}
bool isempty()
{
 return top==-1;
}
void push(int x)
{
    if(isfull())return;
    else
    stack[++top]=x;

}
void init()
{
    temp=ttemp=nullptr;
}
CLLstack* converttoCLL()
{
    if(isempty())return nullptr;
    CLLstack*head=new CLLstack{stack[top],nullptr};//for 10,20....70 topmost of stack is 70 so it should be the last of CLL so LL should be 10,20...70
    temp=head;
   
    for(int i=top-1;i>=0;i--)
    {
        temp=new CLLstack{stack[i],nullptr};
        temp->next=head;
        head=temp;
    }
    ttemp = head;
    while(ttemp->next != nullptr)
    ttemp = ttemp->next;
    ttemp->next = head;
    return head;
}
void displayCLL(CLLstack* head) 
{
    if (!head) return;
    temp = head;
    do 
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}
int main()
{  
    init();
    for (int i = 1; i <= max; i++)
    {
        push(i * 10); // Push 10, 20, ..., 70
    }
    cout << "Stack (top to bottom): ";
    for (int i = top; i >= 0; i--)
    {
    cout << stack[i] << " ";
    }
    cout << endl;
    CLLstack* cllHead = converttoCLL();
    cout << "CLL (head to last): ";
    displayCLL(cllHead);
}