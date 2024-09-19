#include <cstdio>

struct unionFind
{
    int bin[10005];

    unionFind()
    {
        for(int i=1;i<=10002;i++)
            bin[i]=i;
    }

    int anc(int x)
    {
        if(x == bin[x]) return x;
        return bin[x] = anc(bin[x]);
    }
    void uni(int x,int y)
    {
        bin[anc(x)]=anc(y);
    }
    void ask(int x,int y)
    {
        printf("%s\n",anc(x)==anc(y)?"Y":"N");
    }
};

unionFind u;

int main(void)
{
    int n,m,z,x,y;
    scanf("%d%d",&n,&m);

    while(m--)
    {
        scanf("%d%d%d",&z,&x,&y);
        if(z==1) u.uni(x,y);
        else u.ask(x,y);
    }

    return 0;
}