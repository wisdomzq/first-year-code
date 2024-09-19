#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
int a[10005],b[10005];
void swap(int &a,int &b)
{
    int tmp;
    tmp=a,a=b,b=tmp;
}
void quicksort(int *,int,int); 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,ans=0;
    int min=100000000;

    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
    quicksort(a,1,n);
    for(int i=1;i<=n;i++)a[i]-=i;
    quicksort(a,1,n);
    int mid=a[(n+1)/2];
    for(int i=1;i<=n;i++)ans+=abs(a[i]-mid);
    for(int i=-10000;i<=10000;i++)
    {
        int ansy=0;
        for(int j=1;j<=n;j++)
        ansy+=abs(i-b[j]);
        if(ansy<min)min=ansy;
    }
    ans+=min;
    cout<<ans<<endl;
}
void quicksort(int p[],int low,int high)
{
     int i=low,j=high;
     if(i>=j) return;
     int temp=p[low];
     while(i!=j)
     {
        while(p[j]>=temp&&i<j)j--;
        while(p[i]<=temp&&i<j)i++;
        if(i<j)swap(p[i],p[j]);
     }
     swap(p[low],p[i]);
     quicksort(p,low,i-1);
     quicksort(p,i+1,high);
}
