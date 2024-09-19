#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
char a[200005],b[200005],ca[200005],cb[200005];
 bool xa[27],xb[27];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T,n,k;
    cin>>T;
    while(T--)
    {
        bool judge=true;
        cin>>n>>k;
        cin>>a>>b;
        strcpy(ca,a);
        strcpy(cb,b);
        sort(ca,ca+n);
        sort(cb,cb+n);
        if(strcmp(ca,cb)!=0)judge=false;
        else
        {
            for(int i=0;i<n;i++)
        {
        
            if(a[i]!=b[i])
            {
                int p=i+1;
                if(i>=k||(n-p)>=k)
                continue;
                else
                {
                      judge=false;
                      break;
                }
            }
        }
        }
        
        if(!judge)cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
}