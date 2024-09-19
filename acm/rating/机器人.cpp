#include<iostream>
#include<cstring>
using namespace std;
#define ull unsigned long long
char s[200005];
int main()
{
    cin>>s;
    ull n;
    int x,y,minx=1000000,miny=1000000,maxx=0,maxy=0;
    cin>>n;
    int len=strlen(s);
    for(int i=1;i<len;i++)
    {
        if(s[i]=='R')x++,maxx=max(maxx,x);
        if(s[i]=='D')y--,miny=min(miny,y);
        if(s[i]=='U')y++,maxy=max(maxy,y);
        if(s[i]=='L')x--,minx=min(minx,x);
    }
}