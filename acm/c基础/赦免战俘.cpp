#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int a[3000][3000];
int main()
{
    int n,jie,jie1,n1,kuo;
    cin>>n;
    memset(a,0,sizeof(a));
    n1=n;
    jie1=pow(2,n);
    a[jie1][jie1]=1,a[jie1-1][jie1]=1,a[jie1][jie1-1]=1;
    while(n1>1)
    {
         jie=pow(2,n1);
         kuo=pow(2,n-n1+1);
         for(int i=jie1;i>=jie1-kuo+1;i--)
         for(int j=jie1;j>=jie1-kuo+1;j--)
         {
            if(a[i][j]==1)a[i-kuo][j]=1,a[i][j-kuo]=1;
         }
         n1--;
    }
    for(int i=1;i<=jie1;i++)
    {
         for(int j=1;j<=jie1;j++)cout<<a[i][j]<<" ";
         cout<<endl;
    }
   
}