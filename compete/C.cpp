#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    int a,b,c,n,time=0,good,method,recent=0;//method为1：组，method为2：买
    cin>>a>>b>>c;
    n=c/(a-c);
    char s[20];
    cin>>s;
    while(strcmp(s,"end")!=0)
    {
        time++;
        if(time*a<(b+time*c))good=time*a,method=1;//租借更划算
        else good=b+time*c,method=2;
        if((recent+b)<2*good)//good为当前最优方案
        {
            cout<<"buy"<<endl;
            cout.flush();
            cin>>s;
            while(strcmp(s,"end")!=0)
            {
               cout<<"self"<<endl;
               cout.flush();
               cin>>s;
            } 
        }
        else{
            recent+=a;
            cout<<"airline"<<endl;
            cout.flush();
            cin>>s;
        }

    }

}