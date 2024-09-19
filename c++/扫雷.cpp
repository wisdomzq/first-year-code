#include<iostream>
#include<cstring>
using namespace std;
char a[105][105];
int b[105][105];
int main()
{
    int m,n,ans;
    ans=0;
    cin>>m>>n;
    while(m!=0&&n!=0)
    {
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        ans++;
        if(ans>1)cout<<endl;
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                cin>>a[i][j];
            }
        }
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(a[i][j]=='*')b[i][j]=9;
                else 
                {
                    if(a[i-1][j-1]=='*')b[i][j]++;
                    if(a[i-1][j+1]=='*')b[i][j]++;
                    if(a[i+1][j+1]=='*')b[i][j]++;
                    if(a[i+1][j-1]=='*')b[i][j]++;
                    if(a[i][j-1]=='*')b[i][j]++;
                    if(a[i][j+1]=='*')b[i][j]++;
                    if(a[i-1][j]=='*')b[i][j]++;
                    if(a[i+1][j]=='*')b[i][j]++;
                }
            }
        }
        cout<<"Field #"<<ans<<":"<<endl;
        for(int i=1;i<=m;i++)
        {
           for(int j=1;j<=n;j++)
           {
            if(b[i][j]==9)cout<<'*';
            else cout<<b[i][j];
           }
            cout<<endl;
        }
        cin>>m>>n;
    }
}