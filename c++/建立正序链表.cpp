#include <iostream>  
using namespace std;  
  
struct node  
{   int  data;  
    struct node * next;  
};  
  
typedef struct node NODE;  
typedef struct node * PNODE;  
  
void outlist( PNODE );  
int ins_list( PNODE, int );  
int main( )  
{   int num=1;  
    PNODE head;  
  
    head = new NODE;  
    head->next = NULL;  
    head->data = -1;  
    while ( num!=0 )  
    {   cin >> num;  
        if ( num!=0 )  
            ins_list( head, num);  
    }  
    outlist( head );  
    return 0;  
}  
  
void outlist( PNODE head )  
{   PNODE p;  
    p = head->next;  
    while ( p != NULL )  
    {   cout << p->data << endl;;  
        p = p->next;  
    }  
}  
int ins_list( PNODE h, int num ) 
{ 
    PNODE new_code;
    new_code=new NODE;
    new_code->data=num;
    if(h->next==NULL)
    {
        new_code->next=h->next,h->next=new_code;
        return 0;
    }
    while(h->next->data<new_code->data)
       {
        h=h->next;
        if(h->next==NULL)
        {
            new_code->next=h->next,h->next=new_code;
            return 0;
        }
        if(h->next->data>new_code->data)
        {
           new_code->next=h->next,h->next=new_code;
            return 0;
        }
        if(h->next->data==new_code->data)
        return 0;
       }
       if(h->next->data==new_code->data)
        return 0;
       new_code->next=h->next,h->next=new_code;
            return 0; 
} 
