#include<iostream>
#include<algorithm>
using namespace std;
int use[13]={0};
struct point{
    int x,y;
}p[13];
int n,ans=0;
bool cmp(point a,point b)
{
    if(a.y==b.y)return a.x<b.x;
    return a.y<b.y;
}
int go(int num,int q,int begin,int out)//num为访问点的次数，p为哪个点，begin为起点，out判断进出
{
    if(num>1&&q==begin&&out==0)return 1;
    if(out==0)
    {
        if(p[q].y==p[q+1].y)return go(num+1,q+1,begin,1);
        else return 0;
    }
    if(out==1)
    {
        return go(num+1,use[q],begin,0);
    }
}
int judge()
{
    for(int i=1;i<=n;i++)
    if(go(1,i,i,0))return 1;
    return 0;
}
void gopair(int l)
{
    if(l==n+1)
    {
        if(judge()==1)ans++;
        return;
    }
    if(use[l]==0)
    {
        for(int i=l+1;i<=n;i++)
        {
            if(use[i]==0)
            {
                use[i]=l,use[l]=i;
                gopair(l+1);
                use[i]=0,use[l]=0;
            }
        }
    }
    else gopair(l+1);
    return;
    
}
int main()
{
    
     cin>>n;
     for(int i=1;i<=n;i++)cin>>p[i].x>>p[i].y;
     sort(p+1,p+1+n,cmp);
     gopair(1);
     cout<<ans<<endl;
}