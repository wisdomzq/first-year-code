#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
int main()
{
    char word[105],end,begin;
    gets(word);
    int p=0;
    int len=strlen(word);
    bool ju=true;
    while(p<len)
    {
        while(word[p]!=' ') p++;
        end=word[p-1];
        while(word[p]==' ') p++;
        if(p<len)
        begin=word[p];
        if(p>=len)break;
        if((begin-end)!=0&&abs(begin-end)!=32) 
        {
            
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
}