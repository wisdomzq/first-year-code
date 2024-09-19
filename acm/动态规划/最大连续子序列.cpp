#include<iostream>
using namespace std;
int a[200005],n,ans=-100000000;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=2;i<=n;i++)
    {
        a[i]=max(a[i-1]+a[i],a[i]);
        ans=max(ans,a[i]);
    }
    ans=max(ans,a[1]);
    cout<<ans;
}