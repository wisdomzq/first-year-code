#include<iostream>
#include<cstring>
using namespace std;
#define ll long long
ll a[1005][1005];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int T;
    cin>>T;
    while(T--)
    {
          memset(a,0,sizeof(a));
          int n,q,x,y;
          cin>>n>>q;
          for(int i=1;i<=n;i++)
          {
            cin>>x>>y;a[x][y]+=x*y;
          }
          for(int i=1;i<=1000;i++)
          for(int j=1;j<=1000;j++)
            a[i][j]=a[i-1][j]+a[i][j-1]-a[i-1][j-1]+a[i][j];
        while(q--)
        {
            int hs,ws,hb,wb;
            cin>>hs>>ws>>hb>>wb;
            hs++,ws++,hb--,wb--;
            cout<<a[hb][wb]-a[hs-1][wb]-a[hb][ws-1]+a[hs-1][ws-1]<<endl;
        }
    }
}