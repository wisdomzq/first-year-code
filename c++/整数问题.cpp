#include<iostream>
#include<cmath>
void search(int,int);
using namespace std;
int n,ans=0;
int main()
{
    cin>>n;
    if(n==1)cout<<9<<endl;
    else
    {
        for(int i=1;i<=9;i++)
    search(i,1);
    cout<<ans<<endl;
    }
}
void search(int num,int n1)
{
    num*=10;
    if(n1>=n)return;
    n1++;
    for(int i=num;i<num+10;i++)
        if(i%(n1*n1)==0)
        {
            if(n1==n)ans++;
            else search(i,n1);
        }
    
}