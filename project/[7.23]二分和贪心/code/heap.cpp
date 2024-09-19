#include <cstdio>
#include <algorithm>
using namespace std;

#define DAD(x) ((x)/2)
#define LE(x)  ((x)<<1)
#define RT(x)  (((x)<<1)|1)

struct heap
{
    int s[500005];
    int tot;
    
    int top()
    {
        return s[1];
    }

    void modify(int x)
    {
        if(x==1) return;
        if(s[x] > s[DAD(x)])
            swap(s[x],s[DAD(x)]),modify(DAD(x));
    }

    void ins(int key)
    {
        s[++tot]=key;
        modify(tot);
    }

    void repair(int x)
    {
        int tar=s[LE(x)]>s[RT(x)]?LE(x):RT(x);
        if(s[x]<s[tar])
            swap(s[x],s[tar]),repair(tar);
    }

    void pop()
    {
        s[1]=s[tot];
        s[tot--]=0;

        repair(1);
    }
};

heap h;

int ans[100005];

int main(void)
{
    int n,x;
    scanf("%d",&n);

    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        h.ins(x);
    }

    for(int i=1;i<=n;i++)
    {
        ans[i]=h.top();
        h.pop();
    }

    for(int i=n;i>=1;i--)
        printf("%d ",ans[i]);
    
    return 0;
    
}
