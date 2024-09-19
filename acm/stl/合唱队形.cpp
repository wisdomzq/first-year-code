#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int a[200],up[200],down[200];
int main()
{
    int n,maxn=0;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)up[i]=1,down[i]=1;
    for(int i=1;i<=n;i++)
    for(int j=1;j<i;j++)
        if(a[i]>a[j]) up[i]=max(up[i],up[j]+1);
    for(int i=n;i>=1;i--)
    for(int j=n;j>i;j--)
    if(a[i]>a[j]) down[i]=max(down[i],down[j]+1);
    for(int i=1;i<=n;i++)
    {
        if(up[i]+down[i]-1>maxn)
        maxn=up[i]+down[i]-1;
    }
    cout<<n-maxn;
}