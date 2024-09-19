#include<iostream>
using namespace std;
const int size=400005;
int n,sum,a[size],fr[size],ba[size],mfr[size],mba[size];
int get_min(int p[],int l)
{
    int ans=1e9;
    mfr[1]=p[1];
    for(int i=2;i<=l;i++)mfr[i]=min(mfr[i-1]+p[i],min(p[i],0));
    for(int i=2;i<=l;i++)mfr[i]=min(mfr[i-1],mfr[i]);
    mba[l]=p[l];
    for(int i=l-1;i>=1;i--)mba[i]=min(mba[i+1]+p[i],min(p[i],0));
    for(int i=l-1;i>=1;i--)mba[i]=min(mba[i+1],mba[i]);
    for(int i=2;i<l;i++)ans=min(ans,mfr[i-1]+mba[i+1]);
    return ans;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i],sum+=a[i];
    fr[1]=a[1];
    for(int i=2;i<=n;i++)fr[i]=max(fr[i-1],0)+a[i];
    for(int i=2;i<=n;i++)fr[i]=max(fr[i-1],fr[i]);
    ba[n]=a[n];
    for(int i=n-1;i>=1;i--)ba[i]=max(ba[i+1],0)+a[i];
    for(int i=n-1;i>=1;i--)ba[i]=max(ba[i+1],ba[i]);
    int ans=-100000;
    for(int i=1;i<n;i++)ans=max(ans,fr[i]+ba[i+1]);
    ans=max(ans,sum-get_min(a,n-1));
    ans=max(ans,sum-get_min(a+1,n-1));
    cout<<ans;
}
