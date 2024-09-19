#include <stdio.h>  
#include <stdlib.h> 
#include<iostream> 
using namespace std;
typedef struct numLink  
{  
    int no;  
    struct numLink *next;  
}NODE;  
  
NODE *monenode( NODE *head, int m );  
  
void SetLink( NODE *h, int n )  
{  
    NODE *p=NULL, *q=NULL;  
    int i;  
    for( i=0; i<n; i++)  
    {  
        p = (NODE *)malloc(sizeof(NODE));  
        p->no = i+1;  
        p->next = NULL;  
        if( h->next == NULL )  
        {  
            h->next = p;  
            q = p;  
        }  
        else  
        {  
            q->next = p;  
            q = q->next;  
        }  
    }  
    return;  
}  
NODE *monenode( NODE *head,int m )
{
    int k=0,num[200],change[200];
    NODE *p ;
    p=head->next;  
    while ( p!=NULL ) {  
         num[k]=p->no;
        p = p->next; 
        k++; 
    }  
    int ji=0;
    for(int i=m;i<k;i++)
    change[i-m]=num[i],ji++;
    for(int i=0;i<m;i++)
    change[ji+i]=num[i];  
      while ( head->next != NULL )//清空链表
     {  
        p = head->next;  
        head->next= p->next;  
        delete p;  
    } 
    for(int i=k-1;i>=0;i--)
    {
    NODE * q = new NODE;  
    q->no = change[i];  
    q->next = head->next;  
    head->next = q;  
    }  
    return head;
}
 
int main( )  
{  
    int n,m;  
    NODE *head=NULL, *q=NULL;  
    scanf("%d%d",&n,&m);  
    head = (NODE *)malloc(sizeof(NODE));  
    head->no = -1;  
    head->next = NULL;  
  
    SetLink( head, n );  
  
    q = monenode( head, m );  
  
    do  
    {  
        printf("%d ",q->next->no);  
        q = q->next;  
    } while( q->next != NULL );   
    printf("\n");  
    return 0;  
} 