#include<iostream>
using namespace std;
int r[105][105];
int main()
{
    int n,m,x,y,ans=0;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    cin>>x>>y,r[x][y]=1;
    for(int k=1;k<=n;k++)
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
        r[i][j]=r[i][j]|r[i][k]&r[k][j];
        for(int i=1;i<=n;i++)
        {
           int judge=1;
          for(int j=1;j<=n;j++)
          {
            if(i==j)continue;
            judge=judge&(r[i][j]|r[j][i]);
          }
          ans+=judge;
        }
 cout<<ans;

} 
