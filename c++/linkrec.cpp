#include<iostream>
using namespace std;
struct link{
    int data;
    link *next;
};
int main()
{
    int m,n;
    link *head,*p,*rear,*q,*rel,*del;
    head=new link;
    rear=head;
    head->data=1;
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>n;
        if(n==1)
        {
            int d1,d2;
            p=head;
            cin>>d1>>d2;
            while(d1!=p->data)
                 p=p->next;
            q=new link;
            q->next=NULL;
            q->data=d2;
            q->next=p->next;
            p->next=q;
            if(p==rear)
            rear=q;
            rear->next=NULL;
        }
        if(n==2)
        {
            int d3;
            cin>>d3;
            p=head;
            while(d3!=p->data)
                 p=p->next;
            if(p==rear)cout<<0<<endl;
            else
            cout<<p->next->data<<endl;
        }
        if(n==3)
        {
            int d4;
            cin>>d4;
            p=head;
            if(d4==head->data)
            {
            del=p->next;
            p->next=del->next;
            delete del;
            }
            else{
                while(d4!=p->next->data)
                 p=p->next;
                 del=p->next;
            if(del==rear)
            {
                 rear=p;
                 delete del;
                 rear->next=NULL;   
            }
           else 
           {
            p->next=del->next;
            delete del;
           }
            }
        }
    }
}