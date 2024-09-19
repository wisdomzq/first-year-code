#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
 int n,h,r;
 bool judge,visit[1005]={0};
struct ball{
    double x,y,z;
}b[1005];
bool cmp(ball a,ball b)
{
    return a.z<b.z;
}
double dist(ball m,ball n)
{
    return sqrt((m.x-n.x)*(m.x-n.x)+(m.y-n.y)*(m.y-n.y)+(m.z-n.z)*(m.z-n.z));
}
void dfs(ball a,int num)
{
    if(a.z+r>=h)
    {
        judge=1;
        return;
    }
    visit[num]=1;
    for(int i=1;i<=n;i++)
    {
        if(!visit[i]&&dist(a,b[i])<=r*2)
        dfs(b[i],i);
    }
    
}
int main()
{
     int T;
     cin>>T;
     while(T--)
     {
        judge=0;
        memset(visit,0,sizeof(visit));
        memset(b,0,sizeof(b));
        cin>>n>>h>>r;
        for(int i=1;i<=n;i++)cin>>b[i].x>>b[i].y>>b[i].z;
        sort(b+1,b+1+n,cmp);
        for(int i=1;i<=n;i++)
        if(b[i].z-r<=0)
        dfs(b[i],i);
        if(judge)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
     }
}