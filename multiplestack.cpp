#include<iostream>
using namespace std;
#define max 6
struct Mstack
{
    int data[max];
    int topA,topB;
};
Mstack s,*p;
void init()
{
    p=&s;
    p->topA=-1;
    p->topB=max;
}
int emptyA()
{
    if(p->topA==-1)
    return 1;
    else 
    return 0;
}
int emptyB()
{
    if(p->topB==max)
    return 1;
    else
    return 0;
}
int full()
{
    if(p->topA+1==p->topB)
    return 1;
    else 
    return 0;
}
void pushA(int x)
{
    if(full())return;
    p->topA++;
    p->data[p->topA]=x;
}
void pushB(int x)
{
    if(full())return;
    p->topB--;
    p->data[p->topB]=x;
}
int popA()
{
    if(emptyA())return 0;
    int y=p->data[p->topA];
    p->topA--;
    return y;
}
int popB()
{
    if(emptyB())return 0;
    int y=p->data[p->topB];
    p->topB++;
    return y;
}
int main()
{
    init();
    for(int i=0;i<3;i++)
    pushA(i);
    for(int i=3;i<6;i++)
    pushB(i);
    cout<<popA()<<endl;
    cout<<popA()<<endl;
    cout<<popB()<<endl;
    
}