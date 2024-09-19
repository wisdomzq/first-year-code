#include<iostream>
#include<cstring>
using namespace std;
int a[10001],b[10001],g[10001],k[10001];
int main()
{
    int n,x,y,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i]>>b[i]>>g[i]>>k[i];
    cin>>x>>y;
    for(int i=1;i<=n;i++)
    {
         if(x>=a[i]&&x<=(a[i]+g[i])&&y>=b[i]&&y<=(b[i]+k[i]))
         ans=i;
    }
   if(ans>0)cout<<ans;
    else cout<<-1;
}