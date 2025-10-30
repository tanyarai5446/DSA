void reverse()
{
  p=first;
  temp=first;
  while(temp->next!=null){
    ttemp=temp;
    temp=temp->next;
    temp->next=ttemp;
    first=temp;
  }
  
  p->next=null;
}