#include<iostream>
using namespace std;
int card[42][42][42][42],score[360],f[360],n,m,a,b,c,d;
int main()
{
     cin>>n>>m;
     int num;
     for(int i=1;i<=n;i++)cin>>score[i];
     for(int i=1;i<=m;i++)
     {
        cin>>num;
        switch(num)
        {
            case 1:a++;break;
            case 2:b++;break;
            case 3:c++;break;
            case 4:d++;break;
        }
     }

     for(int i=0;i<=a;i++)
        for(int j=0;j<=b;j++)
            for(int k=0;k<=c;k++)
                for(int p=0;p<=d;p++)
                {
                    int r=score[1+1*i+2*j+3*k+4*p];
                    if(i!=0)card[i][j][k][p]=max(card[i][j][k][p],card[i-1][j][k][p]+r);
                    if(j!=0)card[i][j][k][p]=max(card[i][j][k][p],card[i][j-1][k][p]+r);
                    if(k!=0)card[i][j][k][p]=max(card[i][j][k][p],card[i][j][k-1][p]+r);
                    if(p!=0)card[i][j][k][p]=max(card[i][j][k][p],card[i][j][k][p-1]+r);
                }
                    
        cout<<card[a][b][c][d]+score[1];
          
     
     
}