#include<iostream>
#include<cstring>
using namespace std;
int a[5][5];
int search(int i,int j)
{
    int m=a[i][j];
    if(a[i][j-1]==m)return 1;
    if(a[i][j+1]==m)return 1;
    if(a[i-1][j]==m)return 1;
    if(a[i+1][j]==m)return 1;
    return 0;
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        bool ju=false;
        memset(a,0,sizeof(a));
        for(int j=1;j<=4;j++)
        for(int k=1;k<=4;k++)
        cin>>a[j][k];
        for(int j=1;j<=4;j++)
        {
            for(int k=1;k<=4;k++)
         {
            if(ju==false)
            {
               if(search(j,k)==1)
            ju=true,cout<<"YES"<<endl; 
            }
         } 
        }
        if(ju==false)cout<<"NO"<<endl;
    }
}