#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int loc[30];//记录元素位置
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,i;
    cin>>n;
    vector<int> v[n+1];
    string s;
    for(int i=0;i<n;i++)
    v[i].push_back(i),loc[i]=i;
    int num1,num2;
    cin>>s;
    while(s!="quit")
    {
        string s1;
        cin>>num1>>s1>>num2;
        int loc2,loc1;//记录后一个数位置
        loc2=loc[num2],loc1=loc[num1];
        if(loc1==loc2||num1==num2)
        {
             cin>>s;
             continue;
        }
        if(s=="move")
        {
            if(s1=="onto") 
            {
                vector<int> p;
                while(v[loc2].back()!=num2)
                {
                   v[v[loc2].back()].push_back(v[loc2].back());
                   loc[v[loc2].back()]=v[loc2].back();
                   v[loc2].pop_back();
                } 
                while(v[loc1].back()!=num1)
                {
                   v[v[loc1].back()].push_back(v[loc1].back());
                   loc[v[loc1].back()]=v[loc1].back();
                   v[loc1].pop_back();
                } 
                v[loc2].push_back(v[loc1].back());
                loc[num1]=loc2;
                v[loc1].pop_back();
            }
            if(s1=="over")
            {
                 while(v[loc1].back()!=num1)
                {
                   v[v[loc1].back()].push_back(v[loc1].back());
                   loc[v[loc1].back()]=v[loc1].back();
                   v[loc1].pop_back();
                }
                v[loc1].pop_back();
                 v[loc2].push_back(num1);
                 loc[num1]=loc2;
                
            }
        }
        if(s=="pile")
        {
            if(s1=="onto")
            {
                vector<int> p;
                while(v[loc2].back()!=num2)
                {
                   v[v[loc2].back()].push_back(v[loc2].back());
                   loc[v[loc2].back()]=v[loc2].back();
                   v[loc2].pop_back();
                } 
                while(v[loc1].back()!=num1)
                {
                   p.push_back(v[loc1].back());
                   loc[v[loc1].back()]=loc2;
                   v[loc1].pop_back(); 
                }
                p.push_back(v[loc1].back());
                loc[v[loc1].back()]=loc2;
                   v[loc1].pop_back(); 
	            while(!p.empty())
                {
                   v[loc2].push_back(p.back());
                   p.pop_back();
                }
            }
            if(s1=="over")
            {
                vector<int> p;
                 while(v[loc1].back()!=num1)
                {
                   p.push_back(v[loc1].back());
                   loc[v[loc1].back()]=loc2;
                   v[loc1].pop_back(); 
                }
                p.push_back(v[loc1].back());
                 loc[v[loc1].back()]=loc2;
                   v[loc1].pop_back(); 
	             while(!p.empty())
                {
                   v[loc2].push_back(p.back());
                   p.pop_back();
                }
            }
        }
        cin>>s;
    }
    for(int i=0;i<n;i++)
        {
            cout<<i<<":";
            if(!v[i].empty())
             for(int j=0;j<v[i].size();j++)
             cout<<" "<<v[i][j];
                cout<<endl;
        } 
}