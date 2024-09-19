#include <cstdio>

int f(int n)
{
    if(n>100) return 1;
    return 0;
}// 需要找到n=101，它是第一个1

void search()
{
    int l=1,r=1024,mid;


    while(r - l >=5)
    {
        printf("[%d, %d]\n",l,r);
        mid = (l+r)/2;
        if(f(mid) == 0) l=mid;
        else r=mid;
    }

    for(l<=r;f(l)==0;l++);

    printf("%d\n",l);
}

int main(void)
{
    search();
    return 0;
}
