#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
struct student{
    int score,num;
    int sch;
    char name[12],s[505][12],school[12]="?";
}stu[505];
bool cmp(student a1,student a2)
{
    return a1.score>a2.score;
}
bool cdp(student a1,student a2)
{
    return a1.num<a2.num;
}
int n,m,ulu[505];
char uni[505][12];
bool search(char s1[])
{
    for(int i=1;i<=m;i++)
    if(strcmp(uni[i],s1)&&ulu[i]>0)
    {
        ulu[i]--;
        return true;
    }
    return false;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        stu[i].num=i;
        cin>>stu[i].name>>stu[i].score>>stu[i].sch;
        for(int j=1;j<=stu[i].sch;j++)
            cin>>stu[i].s[j];
    }
    for(int i=1;i<=m;i++)
    cin>>uni[i]>>ulu[i];
    sort(stu+1,stu+1+n,cmp);
    for(int i=1;i<=n;i++)
    {
         int p=1;
         while((!search(stu[i].s[p]))&&p<=stu[i].sch) p++;
         if(p<=stu[i].sch)
         strcpy(stu[i].school,stu[i].s[p]);
    }
    sort(stu+1,stu+1+n,cdp);
    for(int i=1;i<=n;i++)
    cout<<stu[i].name<<" "<<stu[i].school<<endl;
}