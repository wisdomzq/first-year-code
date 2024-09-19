#include <iostream>  
using namespace std;  
  
typedef struct node  
{   int data;  
    struct node * next;  
};  
  
typedef struct node NODE;  
typedef struct node * PNODE;  
void outlist( PNODE );  
void sortlist( PNODE, int);  
  
int main( )  
{       int num=1;  
    PNODE head;  
    head = new NODE;  
    head->next = NULL;  
    head->data = -1;  
  
    while ( num!=0 )  
    {   cin >> num;  
        if ( num!=0 )  
            sortlist( head, num);  
    }  
    outlist( head );  
    return 0;  
}  
  
void outlist( PNODE head )  
{   PNODE p;  
    p = head->next;  
    while ( p != NULL )  
    {   cout << p->data << endl;  
        p = p->next;  
    }  
}  
  
void sortlist( PNODE h, int num ) 
{   
    PNODE new_code;
    new_code=new NODE;
    new_code->data=num;
    if(h->next==NULL)
    {
        new_code->next=h->next,h->next=new_code;
        return;
    }
    while(h->next->data<new_code->data)
       {
        h=h->next;
        if(h->next==NULL)
        {
            new_code->next=h->next,h->next=new_code;
            return;
        }
        if(h->next->data>new_code->data)
        {
           new_code->next=h->next,h->next=new_code;
            return;
        }
        if(h->next->data==new_code->data)
        return;
       }
       if(h->next->data==new_code->data)
        return;
       new_code->next=h->next,h->next=new_code;
            return;
} 
 
  