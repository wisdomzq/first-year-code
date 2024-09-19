#include <iostream>  
using namespace std;  
  
typedef int ElemType;   
class List  
{  
    private:  
        typedef struct node {  
            ElemType data;  
            struct node* next;  
            node() {  
                data = -1;  
                next = NULL;  
            }  
            node(int x, struct node* pnext) {  
                data = x;  
                next = pnext;  
            }  
        } node;  
        node * head;  
    public:  
        List() {  
            head = new node;  
        }  
        ~List() {  
            MakeEmpty();  
        }  
        void insert(const ElemType x);  //将元素x插入到L的头部   
        void input( const ElemType flag);  
        void output();  
        void sort();  
        void MakeEmpty();  
};  
  
void List::MakeEmpty()  
{  
    node *p;  
    while ( head->next != NULL ) {  
        p = head->next;  
        head->next= p->next;  
        delete p;  
    }  
}  
  
void List::insert(const ElemType x)     //将元素x插入到链表的头部   
{  
    node * p = new node;  
    p->data = x;  
    p->next = head->next;  
    head->next = p;  
}  
  
void List::input( const ElemType flag)  //flag：数据结束标记  
{  
    ElemType tmp;  
    cin >> tmp;  
    while ( tmp != flag ) {  
        insert (tmp );  
        cin >> tmp;  
    }  
}  
void List::output()
{
    node *p = head->next;  
    while ( p->next!=NULL ) {  
        cout << p->data <<",";  
        p = p->next;  
    } 
    cout<<p->data<<endl;  
}
void List::sort()
{
    int k=0,num[200];;
    node *p = head->next;  
    while ( p!=NULL ) {  
         num[k]=p->data;
        p = p->next; 
        k++; 
    }  
    for(int i=0;i<k;i++) 
    {
        for(int j=i+1;j<k;j++)
        {
            if(num[i]<num[j])
            {
                int tmp=num[i];
                num[i]=num[j];
                num[j]=tmp;
            }
        }
    }
    MakeEmpty();
    for(int i=0;i<k;i++)insert(num[i]);
}

int main()  
{  
    List L;  
    L.input(0);  
    L.sort();  
    L.output();  
    return 0;  
} 