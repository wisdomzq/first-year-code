#include <cstdio>
#include <stack>
using namespace std;
int main(void)
{
    char a[1005];
    stack <char> s;
    scanf("%s",a);
    for(int i=0;a[i];i++)
    {
        if(a[i] == '(' || a[i] == '[' || a[i] == '{')
            s.push(a[i]);
        else    
        {
            if(s.empty()) goto GG;
        

            if( (s.top() == '(' && a[i] == ')') || 
                (s.top() == '[' && a[i] == ']') || 
                (s.top() == '{' && a[i] == '}'))
                s.pop();
            else
                goto GG;
        }
    }
    if(!s.empty()) goto GG;
    // if(s.size())

    puts("Yes");
    return 0;

    GG:
    puts("NO!!!!!!");
    return 0;
}
