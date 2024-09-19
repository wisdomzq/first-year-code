#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
struct task{
    int r,val;
}t[100005];
priority_queue<int> q;
bool cmp(task a,task b)
{
    if(a.r==b.r)return a.val<b.val;
    return a.r<b.r;
}
int n,m,x,y,cnt=0;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        cin>>x>>y;
        if(x>m)continue;
        else{
          t[++cnt].r=m-x+1,t[cnt].val=y;
        }
    }
    int k=cnt;
    sort(t+1,t+1+cnt,cmp);
    for(int i=m;i>=1;i--)
    {
        while(k>=1&&t[k].r>=i)
        {
            q.push(t[k].val);
            k--;
        }
        if(!q.empty())
        {
           ans+=q.top();
           q.pop();
        }
    }
    cout<<ans;
}