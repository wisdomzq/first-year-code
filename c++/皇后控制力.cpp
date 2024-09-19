#include<bits/stdc++.h>
using namespace std;
#define N 100
#define M 50
int n;
int min_ans=0x3f3f3f, ans[N]; 
bool judge_crl(int row[N], int col[N], int rl[N], int lr[N]){//判断皇后是否完全控制棋盘
    for(int x=1;x<=n;x++){
        for(int y=1;y<=n;y++){
            if(row[x]||col[y]||rl[x+y]||lr[M+x-y]){
                continue;
            }else{
                return false;
            }
        }
    }
    return true;
}
int main()
{
    srand(0);
    cin>>n;
    for(int i=0;i<10000;i++){//计算次数
        int num=0;
        int row[N]={0}, col[N]={0}, rl[N]={0}, lr[N]={0}, vis[N]={0};
        for(int x=1;x<=n;x++){//每行的方案
            while(true){
                int y=rand()%(n+1);//[0, n]
                if(!y){
                    vis[x]=0;
                    break;
                }
                if(!col[y]&&!rl[x+y]&&!lr[M+x-y])//该点可行
                {
                    num++;
                    vis[x]=y;
                    row[x]=1;
                    col[y]=1;
                    rl[x+y]=1;
                    lr[M+x-y]=1;
                    break;
                }
            }
        }
        if(judge_crl(row, col, rl, lr)&&num<min_ans){//更新方案
            min_ans=num;
            for(int i=1;i<=n;i++){
                ans[i]=vis[i];
            }
        }
    }
    cout<<min_ans<<endl;
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<" ";
    getchar();
    getchar();
    return 0;
}

