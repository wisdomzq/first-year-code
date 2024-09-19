#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin>>N;
    while(N--)
    {
        string s;
        vector<int> s1,s2;
        int n;
        cin>>s;
        n=s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]=='B'){
                if(!s1.empty())s1.pop_back();
            }else
            if(s[i]=='b'){
                if(!s2.empty())s2.pop_back();
            }
            else{
                if(s[i]>='a'&&s[i]<='z') s2.push_back(i);
            if(s[i]>='A'&&s[i]<='Z') s1.push_back(i);
            }
        }
        for(int c:s1)s2.push_back(c);
        sort(s2.begin(),s2.end());
        for(auto c:s2) cout<<s[c];
		cout<<'\n';	 
    }
}
