#include<iostream>
using namespace std;
#define max 5
struct stack
{
  int data[max];
  int top;
};
stack *p,s1;
void init()
{
    p=&s1;
    p->top=-1;
}
int empty()
{
    if(p->top==-1)
    return 1;
    else 
    return 0;
}
int full()
{
    if(p->top==max-1)
    return 1;
    else 
    return 0;
}
void push(int x)
{
    if(full())return;
    p->top++;
    p->data[p->top]=x;
}
int pop()
{
    int y;
    if(empty())return 0;
    y=p->data[p->top];
    p->top--;
    return y;
}
void dispR() // Display in reverse (top to bottom)
{
    int temp = p->top;
    while (temp != -1)
    {
        cout << p->data[temp] << " ";
        temp--;
    }
    cout << endl;
}

void dispO() // Display in original order (bottom to top)
{
    int temp = 0;
    while (temp <= p->top)
    {
        cout << p->data[temp] << " ";
        temp++;
    }
    cout << endl;
}

int main()
{
    init();
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    cout<<"original array: ";
    dispO();
    cout<<"reversed array: ";
    dispR();
}