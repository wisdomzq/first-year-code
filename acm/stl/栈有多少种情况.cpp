#include<iostream>
#include<cstring>
using namespace std;
int a[20][20];//i表示栈内数字个数，j表示未进栈的数字个数
int main()
{
    int n;
    cin>>n;
    memset(a,0,sizeof(a));
    for(int i=0;i<=n;i++)a[i][0]=1;
     for(int j=1;j<=n;j++)
     for(int i=0;i<=n;i++)
    {
        if(i>=1)
        a[i][j]=a[i-1][j]+a[i+1][j-1];
        if(i==0)
        a[i][j]=a[i+1][j-1];
    }
    cout<<a[0][n];
}