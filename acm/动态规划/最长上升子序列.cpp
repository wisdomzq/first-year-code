#include<iostream>
using namespace std;
int a[5005],f[5005],n,ans;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i],f[i]=1;
    for(int i=1;i<=n;i++)
    for(int j=i+1;j<=n;j++)
        if(a[j]>a[i])f[j]=max(f[i]+1,f[j]);
    for(int i=1;i<=n;i++)ans=max(ans,f[i]);
    cout<<ans;
}