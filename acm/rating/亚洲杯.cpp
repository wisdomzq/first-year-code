#include<iostream>
#include<algorithm>
using namespace std;
struct team{
    int score=0;
    int power,num;
}cou[200050];
bool cmp(team a1,team a2)
{
    if(a1.score!=a2.score)
    return a1.score>a2.score;
    else
    return a1.num<a2.num;
}
int main()
{
       int n,r;
       cin>>n>>r;
       for(int i=1;i<=2*n;i++)
       {
        cin>>cou[i].power;
        cou[i].num=i;
       }
       for(int i=1;i<=r;i++)
       {
        for(int j=1;j<=n;j++)
        {
            int compete1=2*j-1,compete2=2*j;
            if(cou[compete1].power>cou[compete2].power)
            cou[compete1].score+=3;
            else cou[compete2].score+=3;
        }
        sort(cou+1,cou+1+2*n,cmp);
       }
       for(int i=1;i<=2*n;i++)
       if(cou[i].num==1)
       {
        cout<<i;
        return 0;
       }
}