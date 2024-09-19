// #include<iostream>
// #include<vector>
// #include<algorithm>
// #include<cstring>
// using namespace std;
// int maxn[1001]={0},bian[1005][1005]={0},shu[1005];
// bool total=false,mem[1005]={0};
// int n,num;
//  vector<int> p[1001],fa[1001];
//  void dfs(int f,int s)//f为顶端，s为正在遍历的点
//  {
//     if(!total&&(!mem[s]))
//     {
//     fa[f].push_back(s),shu[f]++,mem[s]=1;
//     cout<<f<<" "<<s<<" "<<shu[f]<<endl;
//     for(int i=1;i<=n;i++)cout<<mem[i]<<" ";
//     cout<<endl;
//     if(shu[f]==n) 
//     {
//         for(int i=0;i<fa[f].size();i++)
//     {
//         cout<<fa[f][i]<<" ";
//     }
//     total=true;
//     return ;
//     }

//     for(int i=0;i<p[s].size();i++)
//     {
//         dfs(f,p[s][i]);
//     }
//     shu[f]--,fa[f].pop_back(),mem[s]=0;
//     }
//     return ;
//  }
//  int main()
//  {
//     cin>>n;
//     for(int i=1;i<=n;i++)
//     {
//         cin>>num;
//         while(num!=0)
//         {
//             p[i].push_back(num);
//             cin>>num;
//         }
//     }
//     for(int i=1;i<=n;i++)
//         dfs(i,i);

//  }
#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
int du[1001]={0};
bool total=false,mem[1005]={0};
int n,num;
vector<int> p[1001];
void init()
 {
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>num;
        while(num!=0)
        {
            p[i].push_back(num);
            du[num]++;//入度为0，就是head
            cin>>num;
        }
    }
 }
 void toposort()
 {
      queue<int> q;
      for(int i=1;i<=n;i++)
      if(du[i]==0)cout<<i<<" ",q.push(i);
      while(!q.empty())
      {
        int k=q.front();
        q.pop();
        for(int i=0;i<p[k].size();i++)
        {
            du[p[k][i]]--;
            if(du[p[k][i]]==0)cout<<p[k][i]<<" ",q.push(p[k][i]);
        }

      }
 }
 int main()
 {
         init();
         toposort();
 }