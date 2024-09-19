#include<iostream>
#include<stdio.h>
#include<iomanip>
using namespace std;
void begin(int);
void zao();
void ye();
void begingin();
void coutbreak(int);
void coutdinner(int);
double calbreak(int);
double caldinner(int);
double ans,breakfast,dinner;
int main()
{
    ans=0;
    breakfast=0;
    dinner=0;
	begingin();
}
void begingin()
{
	int n;
	printf("----- 营业时间 -----\n");
    printf("  1. 早餐\n");
    printf("  2. 中餐\n");
    printf("  3. 晚餐\n");
    printf("  4. 夜宵\n");
    printf("  0. 退出\n");
    printf("请输入选项：");
    cin>>n;
    begin(n);
}
void begin(int k)
{
	int n;
	if(k==0)
	{
	ans=breakfast+dinner;
	cout<<"买了这么多美食才花了"<<fixed<<setprecision(2)<<ans<<"。"<<endl;
	}
	if((k==1)||(k==4)||(k==0))//或者直接用“if(k==0) exit(0);”强制结束程序 
	{
	if(k==1)zao();
	if(k==4)ye();
	}
	else
	{
	printf("----- 营业时间 -----\n");	
	printf("  1. 早餐\n");
    printf("  2. 中餐\n");
    printf("  3. 晚餐\n");
    printf("  4. 夜宵\n");
    printf("  0. 退出\n");
    printf("请输入选项：");
    cin>>n;
    begin(n);	
	}
}

void zao()
{
	int k;
	printf("----- 早餐菜单 -----\n");
    printf(" 1. 油条，0.32\n");
    printf(" 2. 豆浆，0.70\n");
    printf(" 3. 鸡蛋，0.50\n");
    printf(" 4. 豆腐脑，1.50\n");
    printf(" 5. 小包子，0.50\n");
    printf(" 0. 选择结束\n");
    printf("请输入选项：");
    cin>>k;
    if((k<6)&&(k>=0))
    coutbreak(k);
    else
    zao();
}
void coutbreak(int k)
{
	switch(k){
		case 1:cout<<"输入油条数量：";calbreak(1);break; 
		case 2:cout<<"输入豆浆数量：";calbreak(2);break; 
		case 3:cout<<"输入鸡蛋数量：";calbreak(3);break; 
		case 4:cout<<"输入豆腐脑数量：";calbreak(4);break; 
		case 5:cout<<"输入小包子数量：";calbreak(5);break; 
		case 0:cout<<"早餐合计：" <<fixed<<setprecision(2)<<breakfast<<"。"<<endl;begingin();break; 
	}
}
double calbreak(int n)
{
	int p;
	cin>>p;
	if(n==1)
	breakfast+=p*0.32;
	if(n==2)
	breakfast+=p*0.70;
	if(n==3)
	breakfast+=p*0.50;
	if(n==4)
	breakfast+=p*1.50;
	if(n==5)
	breakfast+=p*0.50;
	zao();
}
void ye()
{
	int k;
	printf("----- 夜宵菜单 -----\n");
    printf(" 1. 馄饨，2.50\n");
    printf(" 2. 馅饼，1.00\n");
    printf(" 3. 茶鸡蛋，0.60\n");
    printf(" 4. 鸡蛋饼，3.50\n");
    printf(" 0. 选择结束\n");
    printf("请输入选项：");
    cin>>k;
     if((k<5)&&(k>=0))
    coutdinner(k);
    else
    ye();
  
}
void coutdinner(int k)
{
	switch(k){
		case 1:cout<<"输入馄饨数量：";caldinner(1);break; 
		case 2:cout<<"输入馅饼数量：";caldinner(2);break; 
		case 3:cout<<"输入茶鸡蛋数量：";caldinner(3);break; 
		case 4:cout<<"输入鸡蛋饼数量：";caldinner(4);break; 
		case 0:cout<<"夜宵合计：" <<fixed<<setprecision(2)<<dinner<<"。"<<endl;begingin();break; 
	}
}
double caldinner(int n)
{
	int p;
	cin>>p;
	if(n==1)
	dinner+=p*2.50;
	if(n==2)
	dinner+=p*1.00;
	if(n==3)
	dinner+=p*0.60;
	if(n==4)
	dinner+=p*3.50;
	ye();
}
