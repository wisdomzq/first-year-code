#include <cstdio>
#include <vector>
#include <unordered_set>
using namespace std;

// 128MB -> 32000000 个int

struct brute
{
    bool w[1000005];
    void ins(int x)
    {
        w[x]=1;
    }
    void ask(int x)
    {
        printf("%d\n",w[x]);
    }
};

#define ha 233333

struct naive
{
    bool w[ha + 5];
    void ins(int x)
    {
        w[x % ha]=1;
    }
    void ask(int x)
    {
        printf("%d\n",w[x%ha]);
    }
};

struct zip
{
    vector <int> w[ha + 5];
    void ins(int x)
    {
        w[x%ha].push_back(x);
    }
    void ask(int x)
    {
        for(auto i=w[x%ha].begin();i!=w[x%ha].end();i++)
            if(*i == x) goto done;
        puts("No");
        return;

        done:
        puts("Yes");
    }
};

zip B;

unordered_set <int> S;

int main(void)
{
    printf("%d\n",S.count(5));
    S.insert(5);
    printf("%d\n",S.count(5));

    return 0;
}