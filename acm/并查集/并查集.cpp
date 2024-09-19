#include<iostream>
using namespace std;
int f[10010];
int m,n,u,v,w;
int find(int x)
{
    if(f[x]==x)return x;
    else{
        f[x]=find(f[x]);
        return f[x];
    }
}
void check(int a,int b)
{
    int x=find(a),y=find(b);
    if(x!=y)
    {
        f[x]=y;
    }
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)f[i]=i;
    for(int i=1;i<=m;i++)
    {
          cin>>u>>v>>w;
          if(u==1)
            check(v,w);
            else{
              if(find(v)!=find(w))cout<<"N"<<endl;
              else cout<<"Y"<<endl;
            }
    }

}