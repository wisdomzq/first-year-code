#include<iostream>
#include<algorithm>
using namespace std;
struct sun{
    int sp,cv;
}s[3000];
struct cow{
    int mn,mx;
}c[3000];
bool cmp(cow a,cow b)
{
    return a.mn>b.mn;
}
bool smp(sun a,sun b)
{
    return a.sp>b.sp;
}
int main()
{
    int d,l,ans=0;
    cin>>d>>l;
    for(int i=1;i<=d;i++)cin>>c[i].mn>>c[i].mx;
    for(int i=1;i<=l;i++)cin>>s[i].sp>>s[i].cv;
    sort(c+1,c+1+d,cmp);
    sort(s+1,s+1+l,smp);
    for(int i=1;i<=d;i++)
    for(int j=1;j<=l;j++)
    if(c[i].mn<=s[j].sp&&c[i].mx>=s[j].sp&&s[j].cv)
   { s[j].cv--,ans++;
   break;
    }
    cout<<ans<<endl;
}