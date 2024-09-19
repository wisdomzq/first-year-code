#include<iostream>
using namespace std;
int main()
{
    int m,n,k,p,k1,k2;
    int a[200];
    cin>>m>>n;
    k=0;
    while(k<=n)
    {
        a[k]=0;
        k++;
    }
    k=0;
    while(k<m)
    {
        k++;
        k1=0;
        cin>>p;
        while(k1<n)
        {
            k1++;
            if(p>=a[k1]&&k1==n)
            {
                a[k1]=p;
                break;
            }
            if(p>=a[k1]&&k1!=n)
            {
                k2=n;
                while(k2>k1)
                {
                  k2--;
                  a[k2+1]=a[k2];  
                }a[k1]=p;
                break;
            }
        }
    }
    k=0;
    while(k<n)
    {
        k++;
        cout<<a[k];
    }
    cout<<endl;
}