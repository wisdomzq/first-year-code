#include<iostream>
using namespace std;
#define ll long long
ll ans=1000000005;
ll a[1005][1005],minn[1005][1005],maxn[1005][1005],n,m,k,q[1005],p[1005],head,rear;//q作为队列，q为序号
void min_queue(int x)
{
        head=1,rear=0;
    for(int i=1;i<=m;i++)
    {
        while(head<=rear&&q[rear]>=a[x][i])rear--;
        q[++rear]=a[x][i];
        p[rear]=i;
        while(p[head]<=i-k)head++;
        if(i>=k)minn[x][i]=q[head];
    }
}
void max_queue(int x)
{
        head=1,rear=0;
    for(int i=1;i<=m;i++)
    {
        while(head<=rear&&q[rear]<=a[x][i])rear--;
        q[++rear]=a[x][i];
        p[rear]=i;
        while(p[head]<=i-k)head++;
        if(i>=k)maxn[x][i]=q[head];
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)cin>>a[i][j];
    for(int i=1;i<=n;i++)
        min_queue(i),max_queue(i);
    for(int i=1;i<=n-k+1;i++)
    {
        for(int j=k;j<=m;j++)
      {   
        ll maxi=0,mini=100000005,cha;
         for(int l=0;l<k;l++)
         {
               maxi=max(maxi,maxn[i+l][j]);
               mini=min(mini,minn[i+l][j]);
              
         } 
         cha=maxi-mini;
         ans=min(ans,cha);
      }
    }
    cout<<ans;
}