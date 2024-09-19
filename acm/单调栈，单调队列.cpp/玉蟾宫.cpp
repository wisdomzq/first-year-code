#include<iostream>
#include<stack>
#include<cstring>
using namespace std;
int n,m,f[1010][1010],maxx;
char c;
struct node{
    int len,h;
}a[1010];
stack<node> s;
void ask(int x)
{
    memset(a,0,sizeof(a));
    a[1].len=1;
    a[1].h=f[x][1];
    while(!s.empty())s.pop();
    s.push(a[1]);
    for(int i=2;i<=m;i++)
    {
        int w=0;
        while(!s.empty()&&f[x][i]<=s.top().h)
        {
            w+=s.top().len;
            maxx=max(maxx,s.top().h*w);
            s.pop();
        }
        a[i].h=f[x][i],a[i].len=w+1;
        s.push(a[i]);
    }
    int v=0;
    while(!s.empty())
    {
        v+=s.top().len;
        maxx=max(maxx,v*s.top().h);
        s.pop();
    }
}
int main()
{
     ios::sync_with_stdio(0);
     cin.tie(0),cout.tie(0);
     cin>>n>>m;
     for(int i=1;i<=n;i++)
     {
        for(int j=1;j<=m;j++)
        {
            cin>>c;
            if(c=='F')f[i][j]=f[i-1][j]+1;
        }
     }
     for(int i=1;i<=n;i++)ask(i);
     cout<<maxx*3;
}