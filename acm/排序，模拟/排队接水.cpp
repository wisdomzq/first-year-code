#include<iostream>
#include<iomanip>
using namespace std;
void swap(int &x,int &y)
{
    int tmp;
    tmp=x,x=y,y=tmp;
    return ;
}
int main()
{
    int n,a[1001],b[1001];
    double ans=0;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i],b[i]=i;
    for(int i=1;i<n;i++)
    for(int j=i+1;j<=n;j++)
    {
        if(a[i]>a[j])
        swap(a[i],a[j]),swap(b[i],b[j]);
    }
    for(int i=1;i<n;i++)cout<<b[i]<<" ";
    cout<<b[n]<<endl;
    int p=1;
    while(p<n)
    {
         ans+=a[p]*(n-p);
         p++;
    }
    cout<<fixed<<setprecision(2)<<ans/n;
}