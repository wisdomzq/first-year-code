#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int m,*p,*fir,*las,ans=0;
        cin>>m;
        p=new int[2*m+5];
        fir=new int[m+5];
        las=new int[m+5];
        for(int j=1;j<=2*m;j++)  cin>>p[j];
        sort(p+1,p+1+2*m);
        for(int j=1;j<=m;j++) 
        {
            fir[j]=p[j],las[j]=p[j+m];
            if(j>=2) ans+=abs(fir[j]-fir[j-1])+abs(las[j]-las[j-1]);
        }
        cout<<ans<<endl;
        for(int j=1;j<=m;j++)
          cout<<fir[j]<<" "<<las[j]<<endl;
       
    }
}