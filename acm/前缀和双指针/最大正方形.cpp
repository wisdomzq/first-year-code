#include<iostream>
#include<algorithm>
using namespace std;
int a[105][105],f[105][105],n,m,ans=0;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
    {
         cin>>a[i][j];
         if(a[i][j])f[i][j]=1;
    }
   
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i][j]==1)
            f[i][j]=min(f[i-1][j],min(f[i][j-1],f[i-1][j-1]))+1,ans=max(ans,f[i][j]);
        }
    }
    cout<<ans;
}