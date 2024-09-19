#include <queue>
#include <cstdio>
using namespace std;

priority_queue <int> q;

int a[100005];

int main(void)
{
    int n,x,i;

    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&x);
        q.push(x);
    }

    for(i=n;i>=1;i--)
        a[i]=q.top(),q.pop();
    
    for(i=1;i<=n;i++)
        printf("%d ",a[i]);
    
    return 0;
}
