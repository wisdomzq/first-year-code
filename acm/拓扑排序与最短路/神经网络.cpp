#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int ru[105]={0},chu[105]={0},tu[102][102]={0};
vector <int> v[105];
struct point{
    int ori,u;
}po[105];
queue<int> q;
bool judge=false;
priority_queue <int,vector<int>,greater<int> >shu;
int main()
{
    int n,p,be,en,qu;
    cin>>n>>p;
    for(int i=1;i<=n;i++)
    {
         cin>>po[i].ori>>po[i].u;
         if(po[i].ori)q.push(i);
    }
    for(int i=1;i<=p;i++)
    {
         cin>>be>>en>>qu;
         v[be].push_back(en);
         tu[be][en]=qu;
         ru[en]++,chu[be]++;
    }
    for(int i=1;i<=n;i++)
    if(chu[i]==0)shu.push(i);
        while(!q.empty())
        {
            int k=q.front();
            q.pop();
            for(int i=0;i<v[k].size();i++)
            {
                ru[v[k][i]]--;
                if(po[k].ori>0)
                po[v[k][i]].ori+=po[k].ori*tu[k][v[k][i]];
                if(ru[v[k][i]]==0)
                {
                    q.push(v[k][i]);
                    po[v[k][i]].ori-=po[v[k][i]].u;
                }
            } 
        }
        while(!shu.empty())
        {
            int k=shu.top();
            if(po[k].ori>0)
            judge=true, cout<<k<<" "<<po[k].ori<<endl;
            shu.pop();
        }
        if(!judge)cout<<"NULL";
}