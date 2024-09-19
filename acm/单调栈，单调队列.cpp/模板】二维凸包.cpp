#include<iostream>
#include<algorithm>
#include<cmath>
#include<iomanip>
using namespace std;
int n;
struct point{
    double x,y;
}p[100005],s[100005];
double check(point a1,point a2,point b1,point b2)//检查叉积是否大于0，如果是a就逆时针转到b 
{
    return (a2.x-a1.x)*(b2.y-b1.y)-(b2.x-b1.x)*(a2.y-a1.y);
}
void swap(point &a,point &b)
{
    point c;
    c=a,a=b,b=c;
}
double dist(point p1,point p2)//两点间距离。。。 
{
    return sqrt((p2.y-p1.y)*(p2.y-p1.y)+(p2.x-p1.x)*(p2.x-p1.x));
}
bool cmp(point a,point b)
{
   double tmp=check(p[1],a,p[1],b);
   if(tmp>0)return 1;
   if((tmp==0)&&(dist(a,p[1])<=dist(b,p[1])))return 1;
    return 0;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>p[i].x>>p[i].y;
        if((i!=1&&p[i].y<p[1].y)||((i!=1)&&p[i].y==p[1].y&&p[i].x<p[1].x))
        swap(p[1],p[i]);
    }
    sort(p+2,p+1+n,cmp);
    s[1]=p[1];
    int cnt=1;
    for(int i=2;i<=n;i++)
    {
        while(cnt>1&&check(s[cnt-1],s[cnt],s[cnt],p[i])<=0) //判断前面的会不会被踢走，如果被踢走那么出栈
		cnt--;
        cnt++;
        s[cnt]=p[i];
    }
    s[cnt+1]=p[1];
    double ans=0;
    for(int i=1;i<=cnt;i++)
    ans+=dist(s[i],s[i+1]);
    cout<<fixed<<setprecision(2)<<ans;
}