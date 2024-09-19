#include<iostream>
#include<cstring>
using namespace std;
bool total[100000005];
int su[1000005],tmp=0;
void search(int n)
{
    memset(total,1,sizeof(total));
    total[1]=0;
    for(int i=2;i<=n;i++)
    {
        if(total[i])su[++tmp]=i;
        for(int j=1;j<=tmp&&i*su[j]<=n;j++)
        {
              total[i*su[j]]=0;
              if(i%su[j]==0)break;
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int m,n,q;
    cin>>n>>q;
    search(n);
    for(int i=1;i<=q;i++)
    {
        cin>>m;
        cout<<su[m]<<endl;
    }
}

