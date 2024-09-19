#include<iostream>
#include<algorithm>
using namespace std;
#define N 100010
struct pot{
    int x,y;
}a[N];
bool cmp(pot a,pot b)
{
    return a.x<b.x;
}
int n,d,ans;
int p1[N],p2[N],head1,head2,tail1,tail2;//p数组储存位置
int main()
{
    cin>>n>>d;
    for(int i=1;i<=n;i++)cin>>a[i].x>>a[i].y;
    sort(a+1,a+1+n,cmp);
    ans=0x3f3f3f3f;
    head1=head2=1;
    for(int l=0,r=0;l<=n;l++)
    {
        while(head1<=tail1&&p1[head1]<l)head1++;
        while(head2<=tail2&&p2[head2]<l)head2++;
        while((a[p1[head1]].y-a[p2[head2]].y)<d&&r<n)
        {
            r++;
            while(head1<=tail1&&a[p1[tail1]].y<a[r].y)tail1--;
            p1[++tail1]=r;
            while(head2<=tail2&&a[p2[tail2]].y>a[r].y)tail2--;
            p2[++tail2]=r;
        }
        if(r!=n)ans=min(ans,a[r].x-a[l].x);
    }
    if(ans>=0x3f3f3f3f)cout<<-1;
    else cout<<ans;
}