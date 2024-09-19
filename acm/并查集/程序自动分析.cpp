#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int lsh[30000010],f[10000005],m,n,t;
struct node{
    int x,y,e;
}a[10000010];
bool cmp(node a,node b)
{
    return a.e>b.e;
}
int find(int x)
{
    return f[x]==x?x:f[x]=find(f[x]);
}
int main()
{
     ios::sync_with_stdio(0);
     cin.tie(0),cout.tie(0);
     cin>>t;
     while(t--)
     {
    int cnt=0;
    memset(lsh,0,sizeof(lsh));
      memset(a,0,sizeof(a));
      memset(f,0,sizeof(f));
    bool flag=true;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].x>>a[i].y>>a[i].e;
        lsh[++cnt]=a[i].x;
        lsh[++cnt]=a[i].y;
    }
    sort(lsh+1,lsh+1+cnt);
    int col=unique(lsh+1,lsh+1+cnt)-lsh;
    for(int i=1;i<=n;i++)
     {
        a[i].x=lower_bound(lsh+1,lsh+1+col,a[i].x)-lsh;
         a[i].y=lower_bound(lsh+1,lsh+1+col,a[i].y)-lsh;
     }//离散化操作
     for(int i=1;i<=col;i++)f[i]=i;
     sort(a+1,a+1+n,cmp);
     for(int i=1;i<=n;i++)
     {
        int s1=find(a[i].x),s2=find(a[i].y);
        if(a[i].e)    f[s1]=s2;
        else if(s1==s2)
        {
            cout<<"NO"<<endl;
            flag=false;
            break;
        }
       
     }
     if(flag)cout<<"YES"<<endl;

     }
}