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
polynode *first,*temp,*ttemp,*poly1,*poly2,*sum,*diff,*prod,*result,*a,*b;
void init()
{first=temp=ttemp=poly1=poly2=null; }
void insertdata(polynode*& head, int coef, int pow) {
    ttemp = new polynode{coef, pow, nullptr};

    if (!head || pow > head->pow) {//if head==null i.e. emty list or inserted pow is > head->pow
        ttemp->next = head;
        head = ttemp;
        return;
    }

    temp = head;
    while (temp) {
        if (temp->pow == pow) { //when pow = 
            temp->coef += coef;
            return;
        }
        if (!temp->next || temp->next->pow < pow)//when pow small so find correct position untill temp->!=null 
                                                 ////or temp jisko point krra uska next ka pow kam na ho given pow se
            break;// it will break while as soon as we encounter a  pow < given pow and we will be at the position after which we have to insert now pow           
        temp = temp->next;
    }

    ttemp->next = temp->next;
    temp->next = ttemp;
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
   result=null;
   while(p1||p2)
   {
    if(!p2||(p1&&p1->pow>p2->pow)){
    insertdata(result,p1->coef,p1->pow);
    p1=p1->next;
   }
   else if(!p1&&(p2&&p2->pow>p1->pow)){
    insertdata(result,p2->coef,p2->pow);
    p2=p2->next;
   }
   else{
    insertdata(result,p2->coef+p1->coef,p1->pow);
    p1=p1->next;
    p2=p2->next;
   }
   }
   return result;
}
polynode* subPoly(polynode*p1,polynode*p2)
{
  result=null;
  while(p1||p2)
  {
    if(!p2&&(p1&&p1->pow>p2->pow))
    {
      insertdata(result,p1->coef,p1->pow);
      p1=p1->next;
   }
   else if(!p1&&(p2&&p2->pow>p1->pow)){
      insertdata(result,-p2->coef,p2->pow);
      p2=p2->next;
   }
   else{
      insertdata(result,p1->coef-p2->coef,p1->pow);
      p1=p1->next;
      p2=p2->next;
   }
   }
   return result;
    
  }

polynode* mulPoly(polynode*p1,polynode*p2)
{
    result = null;
    for ( a = p1; a != null; a = a->next) {
        for (b = p2; b != null; b = b->next) {
            int newCoef = a->coef * b->coef;
            int newPow = a->pow + b->pow;
            insertdata(result, newCoef, newPow);
        }
    }
    return result;
}

int main()
{   init();
    int n,coef,pow;
    //insert poly1
    cout<<"enter no. of terms in poly1: ";
    cin>>n;
    cout<<"\nenter terms as coef and pow\n";
    for (int i = 0; i < n; ++i) {
    cin >> coef >> pow;
    insertdata(poly1, coef, pow);
    }

    //insert poly2
    cout<<"enter no. of terms in poly2: ";
    cin>>n;
    cout<<"\nenter terms as coef and pow\n";
    for (int i = 0; i < n; ++i) {
    cin >> coef >> pow;
    insertdata(poly2, coef, pow);
    }


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