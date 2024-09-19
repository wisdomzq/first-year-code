#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;
struct student{
    char name[8];
    double score_subject;
    double score_compre;
    double score_total;
    bool zero=true;
    char good='N';
}stu[8004],tmp;
int main()
{
     int n;
     cin>>n;
     for(int i=1;i<=n;i++)
     {
        cin>>stu[i].name>>stu[i].score_subject>>stu[i].score_compre;
        stu[i].score_total=0.8*stu[i].score_subject+0.2*stu[i].score_compre;
        if(stu[i].score_total==0)stu[i].zero=false;
        if(stu[i].score_total>=90)stu[i].good='Y';
     }
    for(int i=1;i<=n-1;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(stu[i].score_total<stu[j].score_total)
            tmp=stu[i],stu[i]=stu[j],stu[j]=tmp;
        }
    }
     for(int i=1;i<=n-1;i++)
     {
        int p,q=i;
        p=0;
        while(q+1<=n&&stu[q].score_total-stu[q+1].score_total<1e-3) q++,p++;   
        if(p>0)
        {  
            for(int j=i;j<i+p;j++)
            {
               for(int k=j+1;k<=i+p;k++)
                 if(strcmp(stu[j].name,stu[k].name)>0&&stu[j].score_total-stu[k].score_total<1e-3) 
                 tmp=stu[j],stu[j]=stu[k],stu[k]=tmp;
            }
            i+=p,p=0;
        }
     }
     for(int i=1;i<=n;i++)
        if(stu[i].zero==true)
        {
            cout<<stu[i].name<<" ";
        cout<<fixed<<setprecision(2)<<stu[i].score_subject<<" ";
        cout<<fixed<<setprecision(2)<<stu[i].score_compre<<" ";
        cout<<fixed<<setprecision(3)<<stu[i].score_total<<" "<<stu[i].good<<endl;
        }
}

