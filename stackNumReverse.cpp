#include<iostream>
using namespace std;
# define max 6
struct Astack
{
    int data[max];
    int top;
};
Astack s,*p;
void init()
{
    p=&s;
    p->top=-1;
}
int rev(int num)
{   //push opration
    while(p->top<max&&num>0)
    {
        p->data[++p->top]=num%10;
        num=num/10;
    }
    //poppping
    int reverse=0;
    int multiplier=1;
    while(p->top!=-1)
    {
        reverse+=p->data[p->top--]*multiplier;
        multiplier*=10;
    }
    return reverse;

}
int main()
{
    init();
    int n;
    cout<<"enter a no. upto 6 digits or less: ";
    cin>>n;
    if(n>max)
    cout<<"pls re enter upto 6 digit\n";
    else{
    int reverse=rev(n);
    cout<<"original: "<<n<<"\n"<<"reversed: "<<reverse;}
    return 0;
}

