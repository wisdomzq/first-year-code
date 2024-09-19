#include<bits/stdc++.h>
using namespace std;
char s[1000005],x[1000005],y[1000005];
int main()
{
     scanf("%s",s);
    bool ju=true;
    memset(x,0,sizeof(x));
    memset(y,0,sizeof(y));
    int len=strlen(s);
    for(int i=len-1;i>=0;i--)
    {
         if(s[i]=='Z')
         {
            if(ju==false)
            {
                puts("-1");
                return 0;
            }
            x[i]='0',y[i]='0';
         }
         if(s[i]=='Y')ju=false,x[i]='0',y[i]='1';
         if(s[i]=='X')ju=false,x[i]='1',y[i]='0';
    }
    puts(x);
   puts(y);
}