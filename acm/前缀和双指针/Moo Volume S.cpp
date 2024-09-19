#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
ll a[100005],f[100005],n;
int main()
{
     unsigned long long ans=0;
     ios::sync_with_stdio(0);
     cin.tie(0);cout.tie(0);
     cin>>n;
     for(int i=1;i<=n;i++)cin>>a[i];
     sort(a+1,a+1+n);
     for(int i=1;i<=n;i++)f[i]=f[i-1]+a[i];
     for(int i=1;i<=n;i++)
     {
        ll num;
        num=f[n]-f[i]-(n-i)*a[i]+(i-1)*a[i]-f[i-1];
        ans+=num;
     }
     cout<<ans;
}