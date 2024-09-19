#include <cstdio>
#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct apple
{
    int x;

    friend bool operator < (apple a,apple b)
    {
        return a.x>b.x;
    }

    apple(int _x=0)
    {
        x=_x;
    }
};

priority_queue <apple> q;

int main(void)
{
    int n,x,i,ans=0;

    scanf("%d",&n);

    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        q.push(apple(x));
    }

    while(q.size() > 1)
    {
        int a,b;
        a=q.top().x,q.pop();
        b=q.top().x,q.pop();
        ans+=a+b;
        q.push(apple(a+b));
    }
    
    printf("%d\n",ans);
    return 0;
}

