#include <iostream>  
using namespace std;  
  
void sort(int *, int, int);  
void input(int *, int );  
void output(int *, int );  
  
int main()  //输入n（n<100)个整数，按照指定的方式（升序或降序）进行排序  
{  
    int n, flag, a[100];  
    cin >> n >> flag;  
    input(a, n);  
    sort(a, n, flag); // flag=0：升序，flag=1：降序  
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
void sort(int p[],int q,int f)
{
    if(f==0)
    {
        for(int i=0;i<q;i++)
        for(int j=i+1;j<q;j++)
        if(p[i]>p[j])
        {
            int temp;
            temp=p[j];
            p[j]=p[i];
            p[i]=temp;
        }
    }
    if(f==1)
    {
        for(int i=0;i<q;i++)
        for(int j=i+1;j<q;j++)
        if(p[i]<p[j])
        {
            int temp;
            temp=p[j];
            p[j]=p[i];
            p[i]=temp;
        }
    }
}