#include<iostream>
#include<cstring>
using namespace std;
int f[200005],d[200005],last,minn,n,num;
int fa(int x)
{
    if(f[x]!=x)
    {
        int last=f[x];
        f[x]=fa(f[x]);
        d[x]+=d[last];
    }
    return f[x];
}
void check(int a,int b)
{
    int az=fa(a),bz=fa(b);
    if(az!=bz)
    {
        f[az]=bz;
        d[a]=d[b]+1;
    }
    else minn=min(minn,d[a]+d[b]+1);
    return;
} 
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)f[i]=i;
    minn=0x777777;
    for(int i=1;i<=n;i++)
    {
        cin>>num;
        check(i,num);  
    }
    cout<<minn;
}