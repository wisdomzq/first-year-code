// #include<iostream>
// #include<algorithm>
// using namespace std;
// long long money[200005];
// struct member{
//     int num;
//     int time[205]={1};
// }me[2005];
// bool queue[200005];
// int main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     int n,m;
//     cin>>n>>m;
//     for(int i=1;i<=n;i++)queue[i]=1,money[i]=0;
//     for(int i=1;i<=m;i++)
//     {
//         int t,m,d;
//         cin>>t>>m>>d;
//         int j=1;
//         while(me[j].time[i]==0)j++;
//         money[j]+=m;//领了钱然后离开
//         for(int k=i;k<=t+d-1;k++) me[j].time[k]=0;
//     }
//     for(int i=1;i<=n;i++)cout<<money[i],cout<<"\n";
// }
#include<iostream>
#include<algorithm>
using namespace std;
long long money[200005];
long long tim[200005];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m1,head;
    cin>>n>>m1;
    for(int i=1;i<=n;i++)tim[i]=0,money[i]=0;
    for(int i=1;i<=m1;i++)
    {
       int t,m,d;
        cin>>t>>m>>d;
        head=0;
        for(int j=1;j<=n;j++)
        if(tim[j]<=t)
        {
            head=j;
            break;  
        }
        money[head]+=m;
        tim[head]=t+d;
    }
    for(int i=1;i<=n;i++)cout<<money[i]<<endl;
}