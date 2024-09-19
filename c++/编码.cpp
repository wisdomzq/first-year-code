#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
long long map[12][27]={0};
void set_map()
{
    for(int i=0;i<26;i++)map[0][i]=i+1;
    for(int i=1;i<10;i++)
    {
        map[i][0]=map[i-1][25]+1;
        for(int j=1;j<26-i;j++)//前一个元素进位
            map[i][j]=map[i][j-1]+map[i-1][25]-map[i-1][j]+1;
        for(int j=26-i;j<26;j++)//非法数等于前一个元素
        map[i][j]=map[i][j-1];
    }
    return; 
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    set_map();
    int n,len;
    cin>>n;
    for(int i=1;i<=n;i++)
    {   
        char a[11];
        int a1[11];
        long long ans=0;
        bool ju=true;
        cin>>a;
        len=strlen(a);
        for(int i=0;i<len;i++)//对字符串排序
       {
        a1[i]=a[i]-'a';
        for(int j=i+1;j<len;j++)
        {
            if(ju==true)
            {
              if(a[i]>=a[j]){
                cout<<0<<"\n";ju=false;break;
            }  
            }
        }
       }//程序开始
       if(ju==true)
       {
          int j=0;
          for(int i=len-1;i>=1;i--)
          {
             ans+=(map[i][a1[j]]-map[i-1][a1[j]+1]);
             j++;
          }
          ans+=map[0][a1[j]];
          cout<<ans<<"\n";
       }
    }
}