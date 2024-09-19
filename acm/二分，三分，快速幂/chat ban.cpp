#include<iostream>
using namespace std;
#define ull unsigned long long
ull def=0;
ull half,all,k;
ull search(ull p,ull begin,ull end,int op)
{
    // if(def>100000)return (end+begin)/2;
    // def++;
    if(op==0)
    {
        ull mid;
        mid=(end+begin)/2;
        if(mid*(mid+1)/2>=p&&(p>(mid*(mid-1)/2))) 
                     return mid; 
        if(begin<=end)
        {   
        //   if(mid*(mid-1)/2>=p&&(p>(mid-1)*(mid-2)/2))
        //     return mid-1;
            if(p>(mid*(mid+1)/2))begin=mid+1;
            if(p<(mid*(mid+1)/2))end=mid-1;
            search(p,begin,end,0);
            
        }
    }
    if(op==1)
    {
        p=all-p;
        ull m=search(p,begin,end,0);
        if(m*(m+1)/2==p)
        return 2*k-1-m;
        else return 2*k-1-m+1; 
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    while(T--)
    {
        ull n,ans=0;
        cin>>k>>n;
        half=k*(k+1)/2;
        all=k*k;
        if(n>=all)
        {
            cout<<2*k-1<<endl;
            continue;
        }
        if(n==half)
        {
            cout<<k<<endl;
            continue;
        }
        if(n>half)ans+=k;
        if(ans==0)
            cout<<search(n,1,k,0)<<endl;
        if(ans!=0)
           cout<<search(n,1,k,1)<<endl;
       
    }

}