#include <cstdio>
#include <algorithm>
using namespace std;

#define LE(x) ((x)<<1)
#define RT(x) (((x)<<1)|1)
#define DAD(x) ((x)>>1)

struct heap
{
    int w[400005];
    int tot;

    int top()
    {
        return w[1];
    }

    void modify(int x)
    {
        if(x == 1) return;
        
        if(w[x] > w[DAD(x)])
        {
            swap(w[x],w[DAD(x)]);
            modify(DAD(x));
        }
    }
    void push(int key)
    {
        w[++tot]=key;
        modify(tot);
    }

    void repair(int x)
    {
        int tar=w[LE(x)]>w[RT(x)]?LE(x):RT(x);

        if(w[x] < w[tar])
        {
            swap(w[x],w[tar]);
            repair(tar);
        }
    }
    void pop()
    {
        swap(w[1],w[tot]);
        w[tot--]=0;

        repair(1);
    }
};

heap h;

int a[100005];

int main(void)
{
    int n,x;
    scanf("%d",&n);

    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        h.push(x);
    }

    for(int i=n;i>=1;i--)
    {
        a[i]=h.top();
        h.pop();
    }

    for(int i=1;i<=n;i++)
        printf("%d ",a[i]);
    
    return 0;
}