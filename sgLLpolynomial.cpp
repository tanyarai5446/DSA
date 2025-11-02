//LL of polynomial and perform operations in it
#include<iostream>
#include<string>
#define null 0
using namespace std;
struct polynode
{
   int coef,pow;
   polynode *next;
};
polynode *first,*temp,*ttemp,*poly1,*poly2,*sum,*diff,*prod;
void init()
{first=temp=ttemp=null; }
void insertdata(polynode* &head,int coef,int pow)
{ 
  init();
  ttemp=new polynode{coef,pow,null};
  if (!head || pow > head->pow) {//if list empty or pow is greater
    ttemp->next=head;
    head=ttemp;
  }
  else//otherwise find correct position
  temp=head;
  while(temp->next&&temp->next->pow>pow)
  temp=temp->next;
  if(temp->pow==pow)
  temp->coef+=coef;
  else{
    ttemp->next=temp->next;
    temp->next=ttemp;
  }
}
void disp(polynode* head)
{
    while (head) {
        cout << head->coef << "x^" << head->pow;
        if (head->next) cout << " + ";
        head = head->next;
    }
    cout << "\n";
}
polynode* addPoly(polynode*p1,polynode*p2)
{

}
polynode* subPoly(polynode*p1,polynode*p2)
{

}
polynode* mulPoly(polynode*p1,polynode*p2)
{

}

int main()
{
    int n,coef,pow;
    //insert poly1
    cout<<"enter no. of terms in poly1: ";
    cin>>n;
    cout<<"\nenter terms as coef and pow";
    cin>>coef>>pow;
    insertdata(poly1,coef,pow);
    //insert poly2
    cout<<"enter no. of terms in poly2: ";
    cin>>n;
    cout<<"\nenter terms as coef and pow";
    cin>>coef>>pow;
    insertdata(poly2,coef,pow);
    //display original
    cout << "\nPolynomial 1: ";
    disp(poly1);
    cout << "Polynomial 2: ";
    disp(poly2);

    // Perform operations
     sum = addPoly(poly1, poly2);
     diff = subPoly(poly1, poly2);
     prod = mulPoly(poly1, poly2);

    // Display results
    cout << "\nSum: ";
    disp(sum);
    cout << "Difference: ";
    disp(diff);
    cout << "Product: ";
    disp(prod);

    return 0;

}