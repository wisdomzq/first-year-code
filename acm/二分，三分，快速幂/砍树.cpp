#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
int a[1000005],n;
ll m;
bool check(int p)
{
    long long ans=0;
    for(int i=1;i<=n;i++)
    if(a[i]>p)
    {
         ans+=(ll)(a[i]-p);
    }
    return ans>=m;
}
int find()
{
    int begin=1,end=1e9+1;
    while(begin+1<end)
    {
        int mid=begin+(end-begin)/2;
        if(check(mid))begin=mid;
        else end=mid;
    }
    return begin;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    cout<<find();
}