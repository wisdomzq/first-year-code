#include<iostream>
#include<cmath>
using namespace std;
#define ll long long
int a[12][12],n,maxx=0,minn=10;
char p[12][12];
int d_find(int,int);
ll create(int,int,int);
ll search(int i,int j)
{
    int dir[9],maxs=0;
    ll tot=0;
    dir[1]=d_find(i-1,j);
    dir[2]=d_find(i-1,j+1);
    dir[3]=d_find(i-1,j-1);
    dir[4]=d_find(i+1,j);
    dir[5]=d_find(i+1,j-1);
    dir[6]=d_find(i+1,j+1);
    dir[7]=d_find(i,j-1);
    dir[8]=d_find(i,j+1);
    for(int p=1;p<=8;p++)maxs=max(maxs,dir[p]);
    for(int p=1;p<=8;p++)
    {
        if(dir[p]==maxs)
        tot=max(tot,create(p,i,j));
    }
    return tot;
}
int d_find(int p,int q)
{
    if(p>n)p=p%n;
    if(p<=0)p+=n;
    if(q<=0)q+=n;
    if(q>n)q=q%n;
    return a[p][q];
}
ll create(int direc,int i1,int j1)
{
    int p[10];
    ll num=0;
    if(direc==1)
    {
        for(int i=1;i<=n-1;i++)
        p[i]=d_find(i1-i,j1);
        for(int i=1;i<=n-1;i++)
        num+=(ll)p[i]*pow(10,n-1-i);
        return num;
    }   
    if(direc==2)
    {
        for(int i=1;i<=n-1;i++)
        p[i]=d_find(i1-i,j1+i);
        for(int i=1;i<=n-1;i++)
       num+=(ll)p[i]*pow(10,n-1-i);
        return num;
    }   
    if(direc==3)
    {
        for(int i=1;i<=n-1;i++)
        p[i]=d_find(i1-i,j1-i);
        for(int i=1;i<=n-1;i++)
       num+=(ll)p[i]*pow(10,n-1-i);
        return num;
    }  
     if(direc==4)
    {
        for(int i=1;i<=n-1;i++)
        p[i]=d_find(i1+i,j1);
        for(int i=1;i<=n-1;i++)
        num+=(ll)p[i]*pow(10,n-1-i);
        return num;
    }   
    if(direc==5)
    {
        for(int i=1;i<=n-1;i++)
        p[i]=d_find(i1+i,j1-i);
        for(int i=1;i<=n-1;i++)
        num+=(ll)p[i]*pow(10,n-1-i);
        return num;
    }   
    if(direc==6)
    {
        for(int i=1;i<=n-1;i++)
        p[i]=d_find(i1+i,j1+i);
        for(int i=1;i<=n-1;i++)
        num+=(ll)p[i]*pow(10,n-1-i);
        return num;
    }   
    if(direc==7)
    {
        for(int i=1;i<=n-1;i++)
        p[i]=d_find(i1,j1-i);
        for(int i=1;i<=n-1;i++)
        num+=(ll)p[i]*pow(10,n-1-i);
        return num;
    }
    if(direc==8)
    {
        for(int i=1;i<=n-1;i++)
        p[i]=d_find(i1,j1+i);
        for(int i=1;i<=n-1;i++)
        num+=(ll)p[i]*pow(10,n-1-i);
        return num;
    } 
    return 0;
}
int main()
{
    ll total=0;
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)cin>>p[i][j],a[i][j]=p[i][j]-'0',maxx=max(maxx,a[i][j]),minn=min(minn,a[i][j]);
    if(minn==maxx)
    {
    for(int i=1;i<=n;i++)
        cout<<minn;
        return 0;
    }
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    if(a[i][j]==maxx)total=max(total,search(i,j));
    total=maxx*pow(10,n-1)+total;
    cout<<total;
}