#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define ull unsigned long long
// bool search_one(int n,ull a_one[],ull a_score[],ull num)
// {
//             int save=lower_bound(a_one+1,a_one+1+n,num)-a_one;
//             if(num==a_one[save])
//              {
//                     cout<<a_score[save]<<" "; 
//                     return true;
//             }
//                  return false;
// }

ull leng[500005];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    while(T--)
    {
        memset(leng,0,sizeof(leng));
        int n,q,op,ci_len=0,ci_one=0;
        ull *one,num,length=0,*score;
        cin>>n>>q;
        one=new ull [500005];//记录1操作时数组长度
        score=new ull[500005];//记录1操作时添加的数
        bool flag=0;
        for(int i=1;i<=n;i++)
        {
            cin>>op>>num;
            if(flag==1)continue;
            if(op==1)
            {
                length++;
                leng[++ci_len]=length;
                one[++ci_one]=length;
                score[ci_one]=num;
            }
            if(op==2)
            {
                if(length>1e18/(num+1))
                {
                    flag=1;continue;
                }
                length*=(num+1);
                leng[++ci_len]=length;
            }
        }
        ull search,len;
        for(int i=1;i<=q;i++)
        {
            bool judge=false;
            cin>>search;
            int save2=(lower_bound(one+1,one+1+ci_one,search)-one);
             if(save2<500005&&one[save2]==search)
             cout<<score[save2]<<" ",judge=true;
            // if(search_one(ci_one,one,score,search))judge=true;
            // for(int j=1;j<=ci_one;j++)
            //      if(search==one[j])
            //      {
            //         cout<<score[j]<<" ",judge=true; 
            //             break;
            //      }
                 if(judge)continue;
            while(search)
            {
                 int save=(upper_bound(leng+1,leng+1+ci_len,search)-leng)-1;
                 len=leng[save];
                //  cout<<search<<" first small "<<len<<endl;
                 if(search%len==0)
                 {
                    if(search!=len)
                    {
                        int save3=(lower_bound(one+1,one+1+ci_one,len)-one);
                       if(save3<500005&&one[save3]==len)
                       cout<<score[save3]<<" ",judge=true;
                    //    if(search_one(ci_one,one,score,len))judge=true;
                    //      for(int j=1;j<=ci_one;j++)
                    // {
                    //     if(len==one[j])
                    //  {
                    //     cout<<score[j]<<" ";
                    //     judge=true;
                    //     break;
                    //  }
                    // }
                   if(!judge)search=len;
                  }
                  else{
                    int save4=(lower_bound(one+1,one+1+ci_one,len)-one);
                       if(save4<500005&&one[save4]==len)
                       cout<<score[save4]<<" ",judge=true;
                    //  if(search_one(ci_one,one,score,len))judge=true;
                    //  for(int j=1;j<=ci_one;j++)
                    // {
                    //     if(len==one[j])
                    //  {
                    //     cout<<score[j]<<" ";
                    //     judge=true;
                    //     break;
                    //  }
                    // }
                    if(!judge)search=leng[save-1];
                 }
                }
                else search%=len;
                if(judge) break;
        }
    }
    cout<<endl;
    delete [] one ;
    delete []score ;
}
}