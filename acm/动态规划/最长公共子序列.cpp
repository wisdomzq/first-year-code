#include<iostream>
#include<algorithm>
using namespace std;
int a[100010],b[100010],map[100010],n,c[100010],cnt;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        map[a[i]]=i;//重新标号，转换为求b的上升子序列
    }
    for(int i=1;i<=n;i++)
    {
           cin>>b[i];
           b[i]=map[b[i]];
    }
     for(int i=1;i<=n;i++)
    {
       if(b[i]>c[cnt])
       {
        c[++cnt]=b[i];
       }
       else{
        c[upper_bound(c+1,c+1+cnt,b[i])-c]=b[i];
       }
    }
    cout<<cnt;
}