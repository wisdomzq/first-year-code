#include<iostream>
#include<cstring>
using namespace std;
int f[52][52];
char a[52];
int main()
{
    cin>>a;
    int len=strlen(a);
    memset(f,0x7F,sizeof(f));
    for(int i=0;i<len;i++)f[i][i]=1;
    for(int l=1;l<len;l++)
    { 
          for(int i=0,j=l;j<len;i++,j++)
          {
              if(a[i]==a[j])f[i][j]=min(f[i+1][j],f[i][j-1]);
              else
              for(int k=i;k<j;k++)
              f[i][j]=min(f[i][k]+f[k+1][j],f[i][j]);
          }
    }	
    cout<<f[0][len-1];
}