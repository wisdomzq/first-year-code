#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
ll a[200005],b[200005],c[200005],ans=0;
int main()
{
     int n,num;
     cin>>n;
     for(int i=1;i<=n;i++)cin>>a[i];
     for(int i=1;i<=n;i++)cin>>b[i];
     for(int i=1;i<=n;i++)c[i]=a[i]-b[i];
     sort(c+1,c+1+n);
     for(int i=1;i<=n;i++)
     {
        num=upper_bound(c+i+1,c+1+n,-c[i])-c;
        ans+=n-num+1;
     }
     cout<<ans;
}