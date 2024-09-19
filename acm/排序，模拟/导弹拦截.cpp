#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
struct point {
    int x,y,lenga,lengb;
}p[100005];
bool cmp(point a,point b)
{
    return a.lenga<b.lenga;
}
int main()
{
    long long x1,y1,x2,y2,n;
    cin>>x1>>y1>>x2>>y2;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>p[i].x>>p[i].y;
        p[i].lenga=(p[i].x-x1)*(p[i].x-x1)+(p[i].y-y1)*(p[i].y-y1);
        p[i].lengb=(p[i].x-x2)*(p[i].x-x2)+(p[i].y-y2)*(p[i].y-y2);
    }
    sort(p+1,p+1+n,cmp);
    int ans=p[n].lenga,maxb=0;
    for(int i=n-1;i>=1;i--)
    {
        if(maxb<p[i+1].lengb)maxb=p[i+1].lengb;
        ans=min(ans,p[i].lenga+maxb);
    }
    cout<<ans;
}