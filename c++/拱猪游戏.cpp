#include<iostream>
#include<cstring>
using namespace std;
int h[20],markc,marks,markd;//h数组记录红心牌在谁手上
int score_h[14]={0,-50,-2,-3,-4,-5,-6,-7,-8,-9,-10,-20,-30,-40};//score_h数组记录h对应的分
void input(char p1[],int p2[],int q,int person)
{
    for(int i=1;i<=q;i++)
    {
        cin>>p1[i]>>p2[i];
        if(p1[i]=='H') h[p2[i]]=person;
        if(p1[i]=='C'&&p2[i]==10)markc=person;
        if(p1[i]=='S'&&p2[i]==12)marks=person;
        if(p1[i]=='D'&&p2[i]==11)markd=person;
    }
}
int search(int p[])//记录哪个人有全部红心
{
    for(int i=1;i<=12;i++)
        for(int j=i+1;j<=13;j++)
            if(p[i]!=p[j])return 0;
            return p[1];
}
int main()
{
    bool ju=true;
    while(ju==true)
    {
    ju=false;
    char ch_a[20],ch_b[20],ch_c[20],ch_d[20];
    int num_a[20],num_b[20],num_c[20],num_d[20],score[5]={0},card[5];
    memset(score,0,sizeof(score));
    cin>>card[1];
    if(card[1]!=0) input(ch_a,num_a,card[1],1),ju=true;
    cin>>card[2];
    if(card[2]!=0) input(ch_b,num_b,card[2],2),ju=true;
    cin>>card[3];
    if(card[3]!=0) input(ch_c,num_c,card[3],3),ju=true;
    cin>>card[4];
    if(card[4]!=0) input(ch_d,num_d,card[4],4),ju=true;
    if(ju==false)  break;
    else
    {
              if(search(h)==0)//红心不在同一家
          {
            for(int i=1;i<=13;i++) score[h[i]]+=score_h[i];
            score[marks]+=-100,score[markd]+=100;
            if(card[markc]>1) score[markc]*=2;
            else score[markc]=50;
            for(int i=1;i<=3;i++)
            {
                if(score[i]>0)cout<<"+";
                cout<<score[i]<<" ";
            }
            if(score[4]>0)cout<<"+";
            cout<<score[4]<<endl;
          }
          else//红心在同一家
          {
              int king=search(h);
              if((marks==king)&&(markd==king))score[king]=700;
              else 
              {
                score[king]=200;
              score[marks]+=-100,score[markd]+=100;
              }
              if(card[markc]>1) score[markc]*=2;
               else score[markc]=50;
              for(int i=1;i<=3;i++)
              {
                if(score[i]>1000)cout<<"+1000"<<" ";
                else{
                    if(score[i]>0)cout<<"+";cout<<score[i]<<" ";
                } 
              }
              if(score[4]>1000)cout<<"+1000";
              else{
                if(score[4]>0)cout<<"+";
              cout<<score[4]<<endl;
              }
          }
      }
     }
} 