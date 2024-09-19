#include<iostream>
#include<cstring>
using namespace std;
int w[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
char y[11]={'1','0','X','9','8','7','6','5','4','3','2'};
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int k;
        char a[20];
        cin>>a;
        k=strlen(a);
        if(k==18)
        {
           int s=0,k1;
           for(int j=0;j<17;j++)
            s+=(a[j]-'0')*w[j];
            k1=s%11;
            if(a[17]==y[k1])cout<<"Valid"<<endl;
            else cout<<"Invalid"<<endl;
        }
        else
        {
            if(k==15)
        {
            char b[20];
            int s=0;
            if((a[12]=='9')&&(a[13]=='9')&&((a[14]=='6')||(a[14]=='7')||(a[14]=='8')||(a[14]=='9')))
            {
                b[6]='1',b[7]='8';
                for(int j=0;j<6;j++)b[j]=a[j];
                for(int j=6;j<15;j++)b[j+2]=a[j];
                for(int j=0;j<17;j++) s+=(b[j]-'0')*w[j];
                b[17]=y[s%11];
            }
            else
            {
               b[6]='1',b[7]='9';
                for(int j=0;j<6;j++)b[j]=a[j];
                for(int j=6;j<15;j++)b[j+2]=a[j];
                for(int j=0;j<17;j++) s+=(b[j]-'0')*w[j];
                b[17]=y[s%11]; 
            }
            for(int i=0;i<18;i++)cout<<b[i];
            cout<<endl;
        }
        else cout<<"Invalid"<<endl;
        }
        
    }
}