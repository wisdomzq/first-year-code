#include<iostream>
#include<algorithm>
#define ll long long
struct cow{
    ll w,s;
}c[50005];
bool cmp(cow a,cow b)
{
    return a.s+a.w<b.s+b.w;
}
using namespace std;
int main()
{
    int n;
    ll risk=-999999999,totw=0;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>c[i].w>>c[i].s;
    sort(c+1,c+1+n,cmp);
    for(int i=1;i<=n;i++)
    {
          risk=max(risk,totw-c[i].s);
          totw+=c[i].w;
    }
    cout<<risk;
}