#include<iostream>
using namespace std;
#define ll long long
ll fa[100010],sum[100010],num[100010],order[100010],anss[100010];
ll n;
int find(int x)
{
    if(fa[x]==x)return x;
    else return fa[x]=find(fa[x]);
}
void merge(ll x,ll y)
{
    ll a=find(x),b=find(y);
    if(a==b)return;
    fa[b]=a;
    sum[a]+=sum[b];
}
int main()
{
      cin>>n;
      for(int i=1;i<=n;i++)cin>>num[i];
      for(int i=1;i<=n;i++)cin>>order[i];
      ll ans=0;
      for(int i=n;i>=1;i--)
      {
        fa[order[i]]=order[i];
        sum[order[i]]=num[order[i]];
        if(fa[order[i]-1])merge(order[i]-1,order[i]);
         if(fa[order[i]+1])merge(order[i]+1,order[i]);
         ans=max(sum[find(order[i])],ans);
         anss[i]=ans;
      }
      for(int i=2;i<=n;i++)cout<<anss[i]<<endl;
      cout<<0<<endl;
      
}