// #include <iostream>
// #include <cstdio>
// #include <cstring>
// using namespace std;

// int dp[1010][1010];
// char s1[1010], s2[1010], ans[1010];

// int main()
// {
//     scanf("%s%s", s1 + 1, s2 + 1);
// 	int len1 = strlen(s1 + 1), len2 = strlen(s2 + 1);
// 	for(int i = 1; i <= len1; i++)
// 	{
// 		for(int j = 1; j <= len2; j++)
// 		{
// 			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
// 			if(s1[i] == s2[j])
//             {
//                 dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
//             }
// 		}
// 	}//LCS 板子
// 	int i = len1, j = len2;
// 	while(dp[i][j] > 0)
//     {
// 		if(s1[i] == s2[j])
//         {
//             ans[dp[i][j]] = s1[i];//反向追踪所有的字符
//             i--, j--;
//         }
// 		else
//         {
// 			if(dp[i][j] == dp[i - 1][j]) i--;
// 			else j--;
// 		}
// 	}
// 	printf("%s", ans + 1);
//     return 0;
// }
#include<bits/stdc++.h>
using namespace std;
int n,m,i,j,dp[3010][3010];char a[3010],b[3010];bool x[3010][3010],y[3010][3010];
void print(int i,int j){
	if(i==0||j==0) return ;
	print(i-x[i][j],j-y[i][j]);//继续往前找
	if(a[i]==b[j]) cout<<a[i];//如果相等，说明这个字符属于LCS
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>a+1>>b+1;
	n=strlen(a+1);m=strlen(b+1);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(a[i]==b[j]) dp[i][j]=dp[i-1][j-1]+1,x[i][j]=1,y[i][j]=1;
			else if(dp[i-1][j]>dp[i][j-1]) dp[i][j]=dp[i-1][j],x[i][j]=1;
			else dp[i][j]=dp[i][j-1],y[i][j]=1;//LCS
	print(n,m);//以栈的形式输出（逆向输出）
	return 0;
}