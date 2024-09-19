#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
struct bean{
   double j,f;
    double value;
};
bool cmp(bean a,bean b)
{
    if(a.value==b.value)return a.j>b.j;
    return a.value<b.value;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int m,n;
    while(cin>>m>>n)
    {
        if(m==-1)break;
        else{
            struct bean *b;
            b=new bean [n+2];
            for(int i=1;i<=n;i++) cin>>b[i].j>>b[i].f,b[i].value=double(b[i].f/b[i].j);
            sort(b+1,b+1+n,cmp);
            double ans=0;
            int mark=1;
            while(m>=b[mark].f&&mark<=n)
            {
                  ans+=b[mark].j;
                  m-=b[mark].f;
                  mark++;
            }
            if(mark<=n)
            ans+=(m/b[mark].f)*b[mark].j;
            cout<<fixed<<setprecision(3)<<ans<<endl;
            delete []b;
        }
    }
}