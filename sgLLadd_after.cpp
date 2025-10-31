#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<iostream>
#define null 0
using namespace std;

 struct node
{
  int data;
    node *next;
};
node *first,*temp,*ttemp,*p,*q,*r,*ptemp,*pttemp,
*ntemp,*nttemp;

void init()
{
 first=temp=ttemp=null;
}
void addnode(int val)
{
  temp=first;
  while(temp->next!=null)
  {
  temp=temp->next;
  
  }
  ttemp=new node;
  ttemp->data=val;
  ttemp->next=null;
  temp->next=ttemp;
}
void createfirst(int val)
{
 first=new node;
  first->data=val;
  first->next=null;
}
void disp()
{
 temp=first;
 while(temp!=null)
 {
   cout<<temp->data<<endl;
   temp=temp->next;
 }
}
void add_after_first(int x)
{
    p=new node;
    p->data=x;
    p->next=first->next;
    first->next=p;
}
void add_after_given(int x,int y)
{
  temp=first;
  while(temp->data!=x)
  temp=temp->next;
  ttemp=new node;
  ttemp->data=y;
  ttemp->next=temp->next;
  temp->next=ttemp;

}

int main()
{
	init();
	createfirst(10);
	addnode(20);
	addnode(30);
	addnode(50);
	addnode(60);
	disp();
    cout<<"\n";
    add_after_first(40);
    disp();
    cout<<"\n";
    add_after_given(30,90);
    disp();
    
}
/*#include<stdio.h>
#include<stdlib.h>


struct Node{
    int data;
    struct Node *next;
};

void linkedListtraversal(struct Node* ptr){
    while(ptr!=NULL)
    {
        printf("Element : %d\n", ptr->data);
        ptr = ptr->next;
    }
}
int main(){
    struct Node *temp;
    struct Node *ttemp;
    struct Node *p;

    // Allocate memory for the nodes in the linked list in Map
    temp = (struct Node *)malloc(sizeof(struct Node));
    ttemp = (struct Node *)malloc(sizeof(struct Node));
    p = (struct Node *)malloc(sizeof(struct Node));

    // link firt and secind node
    temp->data = 7;
    temp->next = ttemp;

    // link second and third node
    ttemp->data = 11;
    ttemp->next = p;

    // Terminate the list at the third node
    p->data = 23;
    p->next = NULL;

    linkedListtraversal(temp);

    return 0;
}*/
