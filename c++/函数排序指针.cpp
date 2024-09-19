#include <iostream>  
using namespace std;   
void sort(int *, int, int (*)(int, int));  
void input(int *, int );  
void output(int *, int );  
int up(int, int);       // a<b:1； a=b:0；a>b:-1反序   
int down(int, int);     // a<b:-1；a=b:0；a>b:1 正序   
int main()  
{  
    int n, flag, a[100];  
    cin >> n >> flag;   // n：数组元素数量； flag=0：升序，flag=1：降序   
    input(a, n);  
    if ( flag==0 )  
        sort(a, n, up);     // 0：升序，1：降序  
    else   
        sort(a, n, down);  
    output(a, n);  
    return 0;  
}  
void input(int p[],int q)
{
    for(int i=0;i<q;i++)
     cin>>p[i];
    
}
void output(int p[],int q)
{
    for(int i=0;i<q;i++)
    cout<<p[i]<<",";
    cout<<endl;
}
int up(int p, int q)       // a<b:1； a=b:0；a>b:-1反序 
{
    if(p<q)return 1;
    if(p==q)return 0;
    if(p>q)return -1;
}  
int down(int p, int q)    // a<b:-1；a=b:0；a>b:1 正序
{
    if(p<q)return -1;
    if(p==q)return 0;
    if(p>q)return 1;
}  
void sort(int p[], int q, int m(int p1, int q1)) 
{
    for(int i=0;i<q;i++)
    {
        for(int j=i+1;j<q;j++)
        if(m(p[i],p[j])==-1)
        {
            int temp;
            temp=p[i];
            p[i]=p[j];
            p[j]=temp;
        }
    }
} 
