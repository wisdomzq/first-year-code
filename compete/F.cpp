#include<iostream>
using namespace std;
int main()
{
    int n,ans=0,min=10000000000;
    int *a,p;
    cin>>n;
    a=new int [n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]<min)min=a[i],p=i;
    }
    ans+=min;
    min=10000000000;
    for(int i=0;i<n;i++)
    {
         if(a[i]<min&&i!=p)min=a[i];
    }
    ans+=min;
    cout<<ans<<endl;
}