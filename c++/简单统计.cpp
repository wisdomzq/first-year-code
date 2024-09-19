#include<iostream>
using namespace std;
int a[10005];
void swap(int &a,int &b)
{
    int tmp;
    tmp=a,a=b,b=tmp;
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
int main()
{
    int n;
    cin>>n;
    for(int p=1;p<=n;p++)
    {
        int m;
        cin>>m;
        for(int i=1;i<=m;i++)cin>>a[i];
        quicksort(a,1,m);
        int ans=1;
        for(int i=1;i<m;i++)
        {
            if(a[i+1]!=a[i])ans++;
        }
        cout<<ans<<endl;
        int k=1;
        for(int i=1;i<=m;i++)
        {
            if(a[i+1]!=a[i])cout<<a[i]<<" "<<k<<endl,k=1;
            else k++;
        }
    }
}