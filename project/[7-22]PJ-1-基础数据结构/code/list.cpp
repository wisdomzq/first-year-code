#include <cstdio>

int nxt[1005];

int main(void)
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&nxt[i]);
    for(int i=1;i;i=nxt[i])
        printf("%d\n",i);
    return 0;
}