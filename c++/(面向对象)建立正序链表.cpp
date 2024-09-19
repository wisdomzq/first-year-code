#include <iostream>  
using namespace std;  
class List  
{  
   private: struct PNODE {  
            int data;  
            PNODE *next;  
            PNODE()  
            {  
                data = -1;  
                next = NULL;  
            }  
            PNODE(int x, PNODE *p=NULL)  
            {  
                data = x;  
                next = p;  
            }  
        };  
         
    public:
    PNODE *head; 
    List()  
        {  
            head = new PNODE;  
        }  
        ~List()  
        {  
            freeList();  
        }  
        void freeList();  
        void sortlist(PNODE *h,int num);  
        void outlist();  
};
void List::freeList()  
{  
    PNODE * del;  
    while ( head->next != NULL ) {  
        del = head->next;  
        head->next = del->next;  
        delete del;  
    }  
}
void List::sortlist(PNODE *head,int num)
{
    PNODE *new_code;
    new_code=new PNODE( num );
    new_code->data=num;
    if(head->next==NULL)
    {
        new_code->next=head->next,head->next=new_code;
        return;
    }
    while(head->next->data<new_code->data)
       {
        head=head->next;
        if(head->next==NULL)
        {
            new_code->next=head->next,head->next=new_code;
            return;
        }
        if(head->next->data>new_code->data)
        {
           new_code->next=head->next,head->next=new_code;
            return;
        }
        if(head->next->data==new_code->data)
        return;
       }
       if(head->next->data==new_code->data)
        return;
       new_code->next=head->next,head->next=new_code;
            return; 
}
void List::outlist()  
{  
    PNODE *p = head->next;  
    while ( p!=NULL ) {  
        cout << p->data <<endl;  
        p = p->next;  
    }   
} 
int main()
{
    List A;
    int num=1;
    while(num!=0)
    {
         cin>>num;
         if ( num!=0 )  
       A.sortlist(A.head, num);  
    }
   A.outlist();  
    return 0;  

}