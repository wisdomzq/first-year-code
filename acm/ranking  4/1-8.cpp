#include<iostream>
using namespace std;
int x1[1005],z1[1005],x2[1005],z2[1005],m1,n1,jiax[3010],jiaz[3010],chengx[10010],chengz[10010];
int main()
{
    cin>>m1;
    for(int i=1;i<=m1;i++)
        cin>>x1[i]>>z1[i];
    cin>>n1;
    for(int i=1;i<=n1;i++)
        cin>>x2[i]>>z2[i];
        int chengmax=0;
    for(int i=1;i<=m1;i++)
    {
        for(int j=1;j<=n1;j++)
        {
            chengx[z1[i]+z2[j]]+=x1[i]*x2[j];
            chengmax=max(chengmax,z1[i]+z2[j]);
        }
    }
    bool cj=false;
    for(int i=chengmax;i>=0;i--)
    if(chengx[i]!=0)cj=true;
    if(cj==false)cout<<0<<" "<<0<<endl;
    else{
        cout<<chengx[chengmax]<<" "<<chengmax;
    for(int i=chengmax-1;i>=0;i--)
    {
        if(chengx[i]!=0)cout<<" "<<chengx[i]<<" "<<i;
    }
   cout<<endl;
    }
    for(int i=1;i<=m1;i++)
        jiax[z1[i]]+=x1[i];
    for(int i=1;i<=n1;i++)
        jiax[z2[i]]+=x2[i];
    int jiamax;
    jiamax=z1[1]>z2[1]?z1[1]:z2[1];
    bool jj=false;
    for(int i=jiamax;i>=0;i--)
    if(jiax[i]!=0)jj=true;
    if(jj==false)cout<<0<<" "<<0<<endl;
    else{
    cout<<jiax[jiamax]<<" "<<jiamax;
    for(int i=jiamax-1;i>=0;i--)
    if(jiax[i]!=0)cout<<" "<<jiax[i]<<" "<<i;
    }
}