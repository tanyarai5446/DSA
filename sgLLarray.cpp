//input an array and store it as LL then display it as array
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<iostream>
#define null 0
using namespace std;

 struct array
{
  int data;
    array *next;
};
array *first,*temp,*ttemp,*p,*q,*r,*ptemp,*pttemp,
*ntemp,*nttemp;

void init()
{
 first=temp=ttemp=null;
}

void arraytoLL(int a[],int n)
{ 
   int i=0;
   while(i<n)
   {
   ttemp=new array;
   ttemp->data=a[i];
   ttemp->next=null;
   i++;
   if(first==null)
   {
    first=ttemp;
    temp=first;
   }
   else
   {
    temp->next=ttemp;
    temp=ttemp;
   }
   }
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
int outputarray[100];
void LLtoarray()
{   
    int i=0;
    temp=first;
    while(temp!=null)
    {
        outputarray[i++]=temp->data;
        temp=temp->next;
    }
}

void dispoutputarray(int n)
{
  for(int i=0;i<n;i++)
  {
    cout<<outputarray[i]<<" ";
  }
  cout<<endl;
}
int main()
{
    int n;
    cout<<"enter n: ";
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
      cin>>a[i];
    }
    cout<<"array stored as LL: \n";
    arraytoLL(a,n);
    disp();
    cout<<"\nLL displayed as array\n";
    LLtoarray();
    dispoutputarray(n);
}