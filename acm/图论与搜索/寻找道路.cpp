// #include<vector>
// #include<iostream>
// using namespace std;
// int n,m,x,y,begin1,end1,minn=10005,ans;
// bool total=false;
// bool ch[10005]={0},bi[10005]={0},chout[10005]={0};//ch记录数合不合法，bi数组记录数被取过没有
// vector<int> in[10005],out[10005];//统计每个点发出哪些边
// bool judge(int num)
// {
//     for(int i=0;i<out[num].size();i++)
//     if(!ch[out[num][i]])return false;
//     return true;
// }
// void mark(int x)
// {
//     bi[x]=1; 
//     if(!judge(x))return ;
//     for(int i=0;i<in[x].size();i++)
//     {
//        if(!bi[in[x][i]])
//        {
//         ch[in[x][i]]=1;bi[in[x][i]]=1;chout[in[x][i]]=1;
//         // cout<<in[x][i]<<endl;
//        }
//        mark(in[x][i]);
//     }
// }
// void ahead(int x)
// {
//      for(int i=0;i<out[x].size();i++)
//      {
//         if(ch[out[x][i]])
//         {
//             if(!judge(out[x][i])) chout[out[x][i]]=0;
//             ahead(out[x][i]);
//         }
        
//      }
// }
// void bfs(int x)
// {
//     if(x==end1) 
//     {
//         total=true;
//         minn=min(ans,minn);
//         return;
//     }
//     for(int i=0;i<out[x].size();i++)
//     {
//         if(ch[out[x][i]]&&chout[out[x][i]])
//         {
//             ans++;
//             // cout<<out[x][i]<<" "<<ans<<endl;
//             bfs(out[x][i]);
//             ans--;
//         }
//     }
// }
// int main()
// {
//     cin>>n>>m;
//     for(int i=1;i<=m;i++)
//     {
//         cin>>x>>y;
//         if(x!=y)
//         {
//              in[y].push_back(x);
//         out[x].push_back(y);
//         }
       
//     }
//     cin>>begin1>>end1;
//     ch[end1]=1;
//     chout[end1]=1;
//     mark(end1);
//     ahead(begin1);
//     ans=0;
//     chout[begin1]=judge(begin1);
//     // cout<<chout[begin1]<<endl;
//     if(ch[begin1]&&chout[begin1])
//     bfs(begin1);
//     else  
//     {
//         cout<<-1;
//         return 0;
//     }
//     if(total)
//     cout<<minn;
//     else cout<<-1;
// }
#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
int n,m,s,t,u,v,vis1[maxn],dis[maxn];
vector<int>mp[maxn];
vector<int>reb[maxn];
queue<int>q,p;
void bfs1(int x){//第一次标记所有终点能到的点
	q.push(x),vis1[x]=1;
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int i=0;i<(int)reb[u].size();i++){
			int v=reb[u][i];
			if(!vis1[v]){
				vis1[v]=1,q.push(v);//标记
			}
		}
	}
}
bool check(int x){//看是否能到达终点
	for(int i=0;i<mp[x].size();i++){
		if(!vis1[mp[x][i]])return false;
	}
	return true;
}
bool bfs2(int x){//第二次从原点遍历所有点
	p.push(x);
	while(!p.empty()){
		int u=p.front();p.pop();
		if(!check(u))continue;
		for(int i=0;i<mp[u].size();i++){
			int v=mp[u][i];
			if(dis[v]==-1){
				dis[v]=dis[u]+1;//记录距离
				p.push(v);
				if(v==t){//找到了就输出
					printf("%d",dis[t]+1);
					return true;
				}
			}
		}
	}
	return false;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>u>>v;
		mp[u].push_back(v);
		reb[v].push_back(u);//建立反边
	}
	cin>>s>>t;
	bfs1(t);
	memset(dis,-1,sizeof(dis));
	if(!bfs2(s))//没找到就输出-1
		printf("-1\n");
	return 0;
}