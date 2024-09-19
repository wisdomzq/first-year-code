#include<iostream>
#include<cstring>
using namespace std;
int a[105],ans=0;
void search_0(int p[],int a,int b);
void water(int p[],int begin,int end)
{
    int minn=1000;
     for(int i=begin;i<=end;i++)minn=min(minn,p[i]);
     ans+=minn;
     for(int i=begin;i<=end;i++)p[i]-=minn;
     search_0(p,begin,end);
}
void search_0(int p[],int begin,int end)
{
   int j=begin;
   while(j<=end)
   {
     while(p[j]==0&&j<=end)j++;//去掉前缀0
     if(j==end+1)return;
     int be1=j;
     while(p[j]!=0&&j<=end)j++;
     water(p,be1,j-1);
     j++;
   }
}

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    search_0(a,1,n);
    cout<<ans;
}