#include<iostream>
using namespace std;
int a[5005][5005],n,m,x,y,v,maxx=0,maxy=0;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int fans=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>x>>y>>v,a[x+1][y+1]+=v;

    for(int i=1;i<=5001;i++)
        for(int j=1;j<=5001;j++)
       a[i][j]=a[i-1][j]+a[i][j-1]-a[i-1][j-1]+a[i][j];
   
    for(int i=m;i<=5001;i++)
    for(int j=m;j<=5001;j++)
    {
         int num=a[i][j]-a[i-m][j]-a[i][j-m]+a[i-m][j-m];
         fans=max(fans,num);
    }
    cout<<fans;
}