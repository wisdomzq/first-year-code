#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n,m,ans=0;
    int num[1005];
    cin>>n>>m;
    vector<int> v;
    for(int i=1;i<=m;i++)
    {
        cin>>num[i];
        bool search=false;
        for(vector<int>::iterator it=v.begin();it!=v.end();it++)
        {
            if(*it==num[i]) search=true;
        }
        if(search==false)
        {
            if(v.size()==n)   v.erase(v.begin());
                v.push_back(num[i]);
            ans++;
        }
    }
    cout<<ans;
}