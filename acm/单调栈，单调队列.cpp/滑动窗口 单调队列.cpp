#include<iostream>
using namespace std;
#define ll long long
ll a[1000005],n,m,q[1000005],p[1000005],head,rear;//q作为队列，q为序号
void min_queue()
{
    head=1,rear=0;
    for(int i=1;i<=n;i++)
    {
        while(head<=rear&&q[rear]>=a[i])rear--;
        q[++rear]=a[i];
        p[rear]=i;
        while(p[head]<=i-m)head++;
        if(i>=m)cout<<q[head]<<" ";
    }
    cout<<endl;
}
void max_queue()
{
    head=1,rear=0;
    for(int i=1;i<=n;i++)
    {
        while(head<=rear&&q[rear]<=a[i])rear--;
        q[++rear]=a[i];
        p[rear]=i;
        while(p[head]<=i-m)head++;
        if(i>=m)cout<<q[head]<<" ";
    }
    cout<<endl;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    min_queue();
    max_queue();

}