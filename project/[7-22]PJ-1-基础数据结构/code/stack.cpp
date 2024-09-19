#include <cstdio>

int s[10005];
int tot=0;

// s[1],s[2],s[3],... s[tot]
// ->
// s[1],s[2],s[3],... s[], s[tot](x)

void push(int x)
{
    s[++tot]=x;
}

void pop()
{
    tot--;
}

int top()
{
    return s[tot];
}

void print()
{
    for(int i=1;i<=tot;i++)
        printf("%d ",s[i]);
    puts("");
}

int main(void)
{
    push(1);print();printf("Top = %d\n",top());
    push(2);print();printf("Top = %d\n",top());
    push(3);print();printf("Top = %d\n",top());
    pop();print();printf("Top = %d\n",top());
    pop();print();printf("Top = %d\n",top());
    push(4);print();printf("Top = %d\n",top());
    push(5);print();printf("Top = %d\n",top());
    pop();print();printf("Top = %d\n",top());
    pop();print();printf("Top = %d\n",top());
    pop();print();printf("Top = %d\n",top());
    
    return 0;
}