#include<iostream>
#include<cstring>
using namespace std;
int a[201],sum[201],fx[201][201]={0},fn[201][201],maxx=-1,minn=0x7f7f7f7f,n;
int su(int i,int j)
{
    return sum[j]-sum[i-1];
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i],a[n+i]=a[i];
    int len=2*n-1;
    for(int i=1;i<=len;i++)sum[i]=sum[i-1]+a[i];
      memset(fn,0x7f,sizeof(fn));
    for(int i=0;i<=200;i++) fn[i][i] = 0;
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=len-i+1;j++)
        {
            for(int k=j;k<j+i-1;k++)
            {
                fx[j][j+i-1]=max(fx[j][j+i-1],fx[j][k]+fx[k+1][j+i-1]);
                fn[j][j+i-1]=min(fn[j][j+i-1],fn[j][k]+fn[k+1][j+i-1]);
                
            }fx[j][j+i-1]+=su(j,j+i-1);
                fn[j][j+i-1]+=su(j,j+i-1);
        }
    }
    for(int i=1;i<=n;i++)
    maxx=max(maxx,fx[i][i+n-1]),minn=min(minn,fn[i][i+n-1]);
    cout<<minn<<endl;
    cout<<maxx;
}