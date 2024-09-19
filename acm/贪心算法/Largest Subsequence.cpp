#include<iostream>
#include<algorithm>
using namespace std;
bool cmp(char x,char y)
{
    return x<y;
}
char a[200005],b[200005];
int q[200005];
int main()
{
      int T;
      cin>>T;
      while(T--)
      {
        int n,ans=0;
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i],b[i]=a[i];
        sort(b+1,b+1+n,cmp);
        bool judge=true;
        for(int i=1;i<=n;i++)
        if(a[i]!=b[i])
        { judge=false;break;}
        if(judge){
            cout<<0<<endl;continue;}
        int t=0;
        for(int i=1;i<=n;i++)
        {
            while(a[q[t]]<a[i]&&t)t--;
            q[++t]=i;
        }
        ans=1;
        while(ans<t&&a[q[ans]]==a[q[ans+1]])ans++;
        ans=t-ans;
        for(int i=1;i<=t;i++)a[q[i]]='_';
        for(int i=1;i<=n;i++)
        {
            if(a[i]=='_')continue;
            if(a[i]!=b[i])ans=-1;
        }
          cout<<ans<<endl;
      }
}