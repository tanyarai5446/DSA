//merging LL of even and odd into one LL
#include<iostream>
#define null 0
using namespace std;

 struct NatNo
{
  int data;
  NatNo *next;
};
NatNo *first,*temp,*ttemp,*p,*q,*r,*ptemp,*pttemp,
*ntemp,*nttemp,*efirst=null,*ofirst=null,*etemp=null,*otemp=null;

void init()
{
 first=temp=ttemp=efirst=ofirst=null;
}
void createEfirst(int val)
{
  efirst=new NatNo;
  efirst->data=val;
  efirst->next=null;
}
void createOfirst(int val)
{
  ofirst=new NatNo;
  ofirst->data=val;
  ofirst->next=null;
}

void addnode(NatNo* head,int val)
{
  temp=head;
  while(temp->next!=null)
  {
  temp=temp->next;
  }
  ttemp=new NatNo;
  ttemp->data=val;
  ttemp->next=null;
  temp->next=ttemp;
}


void disp(NatNo* head)
{
 temp=head;
 while(temp!=null)
 {
   cout<<temp->data<<endl;
   temp=temp->next;
 }
}
void mergedLL()
{
    etemp=efirst;
    otemp=ofirst;
    //first=null;
    //temp=null;
    while(etemp!=null&&otemp!=null)
    {   
        ttemp=new NatNo;
        if(etemp->data<otemp->data)
        {
            ttemp->data =etemp->data;
            etemp=etemp->next;
        }
        else
        {
            ttemp->data=otemp->data;
            otemp=otemp->next;
        }
        ttemp->next=null;
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
    //add remaining even
    while(etemp!=null)
    {
        ttemp= new NatNo;
        ttemp->data=etemp->data;
        ttemp->next=null;
        temp->next=ttemp;
        temp=ttemp;
        etemp=etemp->next;
    }
    //add rwmaining odd
    while(otemp!=null)
    {
        ttemp=new NatNo;
        ttemp->data=otemp->data;
        ttemp->next=null;
        temp->next=ttemp;
        temp=ttemp;
        otemp=otemp->next;

    }


}
int main()
{
    init();
    createEfirst(2);
    addnode(efirst,4);
    addnode(efirst,6);
    addnode(efirst,8);
    cout<<"even LL: \n";
    disp(efirst);
    cout<<"odd LL: \n";
    createOfirst(1);
    addnode(ofirst,3);
    addnode(ofirst,5);
    addnode(ofirst,7);
    addnode(ofirst,9);
    disp(ofirst);
    cout<<"merged LL: \n";
    mergedLL();
    disp(first);

}