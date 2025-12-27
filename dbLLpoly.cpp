#include<iostream>
using namespace std;
struct poly
{
    int coef,pow;
    poly *prev,*next;
};
poly *first,*temp,*ttemp,*poly1,*poly2,*sum,*diff,*prod;
void insertdata(poly *&first,int coef,int pow)
{
    ttemp=new poly{coef,pow,nullptr,nullptr};
    if(!first||pow>first->pow)
    {
    ttemp->next=first;
    if(first)first->prev=ttemp;
    first=ttemp;
    return;
    }
    poly *curr=first;
    while(curr->next&&curr->next->pow>=pow)
    curr=curr->next;
    if(curr->pow==pow)
    curr->coef+=coef;
    else
    {
        ttemp->next = curr->next;
        if (curr->next) curr->next->prev = ttemp;
        curr->next = ttemp;
        ttemp->prev = curr;
    }
}
poly * addpoly(poly*p1,poly*p2)
{
   poly *result=nullptr;
   while(p1&&p2)
   {
    if(p1->pow>p2->pow)
    {
        insertdata(result,p1->coef,p1->pow);
        p1=p1->next;
    }
    else if(p2->pow>p1->pow)
    {
        insertdata(result,p2->coef,p2->pow);
        p2=p2->next;
    }
    else{
        insertdata(result,p1->coef+p2->coef,p1->pow);
        p1=p1->next;
        p2=p2->next;}
    }
    while (p1) {
        insertdata(result, p1->coef, p1->pow);
        p1 = p1->next;
    }
    while (p2) {
        insertdata(result, p2->coef, p2->pow);
        p2 = p2->next;
    }
    return result;
 }
 poly* subpoly(poly*p1,poly*p2)
 {
    poly*result=nullptr;
    while(p1&&p2)
    {
        if(p1->pow>p2->pow)
        {
            insertdata(result,p1->coef,p1->pow);
            p1=p1->next;
        }
        else if(p2->pow>p1->pow)
        {
            insertdata(result,-p2->coef,p2->pow);
            p2=p2->next;
        }
        else{
            insertdata(result,p1->coef-p2->coef,p1->pow);
            p1=p1->next;
            p2=p2->next;}
    }
    while (p1) {
        insertdata(result, p1->coef, p1->pow);
        p1 = p1->next;
    }
    while (p2) {
        insertdata(result, -p2->coef, p2->pow);
        p2 = p2->next;
    }

    return result;
 }
poly* mulpoly(poly*p1,poly*p2)
{
    poly*result=nullptr;
    for(poly*i=p1;i!=nullptr;i=i->next)
    {
        for(poly*j=p2;j!=nullptr;j=j->next)
        {
            int newcoef=i->coef*j->coef;
            int newpow=i->pow+j->pow;
            insertdata(result,newcoef,newpow);       

        }
    }
    return result;
}
void display(poly* head) {
    while (head) {
        cout << head->coef << "x^" << head->pow;
        if (head->next && head->next->coef >= 0) cout << " + ";
        head = head->next;
    }
    cout << endl;
}
int main()
{
    poly* poly1 = nullptr;
    poly* poly2 = nullptr;

insertdata(poly1, 3, 2); // 3x^2
insertdata(poly1, 5, 1); // 5x^1
insertdata(poly2, 2, 1); // 2x^1
insertdata(poly2, 4, 0); // 4

poly* sum = addpoly(poly1, poly2);
poly* diff = subpoly(poly1, poly2);
poly* prod = mulpoly(poly1, poly2);

display(sum);   // 3x^2 + 7x^1 + 4
display(diff);  // 3x^2 + 3x^1 - 4
display(prod);  // 6x^3 + 22x^2 + 20x^1
}
