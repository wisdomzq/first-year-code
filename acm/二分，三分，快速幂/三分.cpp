//题目名字为三分，求导变成二分
#include<iostream>
double a[16],b[16];
int n;
using namespace std;
double d(double x)
{
    double ans=0;
    for(int i=n;i>=1;i--)ans=b[i]+ans*x;
    return ans;
}
int main()
{
    double begin,end,mid;
    cin>>n>>begin>>end;
    for(int i=n;i>=0;i--)cin>>a[i],b[i]=a[i]*i;
    while(end-begin>1e-6)
    {
        mid=(begin+end)/2;
        if(d(mid)>0)begin=mid;
        else end=mid;
    }
    cout<<begin;


}