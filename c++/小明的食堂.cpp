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
	printf("----- Ӫҵʱ�� -----\n");
    printf("  1. ���\n");
    printf("  2. �в�\n");
    printf("  3. ���\n");
    printf("  4. ҹ��\n");
    printf("  0. �˳�\n");
    printf("������ѡ�");
    cin>>n;
    begin(n);
}
void begin(int k)
{
	int n;
	if(k==0)
	{
	ans=breakfast+dinner;
	cout<<"������ô����ʳ�Ż���"<<fixed<<setprecision(2)<<ans<<"��"<<endl;
	}
	if((k==1)||(k==4)||(k==0))//����ֱ���á�if(k==0) exit(0);��ǿ�ƽ������� 
	{
	if(k==1)zao();
	if(k==4)ye();
	}
	else
	{
	printf("----- Ӫҵʱ�� -----\n");	
	printf("  1. ���\n");
    printf("  2. �в�\n");
    printf("  3. ���\n");
    printf("  4. ҹ��\n");
    printf("  0. �˳�\n");
    printf("������ѡ�");
    cin>>n;
    begin(n);	
	}
}

void zao()
{
	int k;
	printf("----- ��Ͳ˵� -----\n");
    printf(" 1. ������0.32\n");
    printf(" 2. ������0.70\n");
    printf(" 3. ������0.50\n");
    printf(" 4. �����ԣ�1.50\n");
    printf(" 5. С���ӣ�0.50\n");
    printf(" 0. ѡ�����\n");
    printf("������ѡ�");
    cin>>k;
    if((k<6)&&(k>=0))
    coutbreak(k);
    else
    zao();
}
void coutbreak(int k)
{
	switch(k){
		case 1:cout<<"��������������";calbreak(1);break; 
		case 2:cout<<"���붹��������";calbreak(2);break; 
		case 3:cout<<"���뼦��������";calbreak(3);break; 
		case 4:cout<<"���붹����������";calbreak(4);break; 
		case 5:cout<<"����С����������";calbreak(5);break; 
		case 0:cout<<"��ͺϼƣ�" <<fixed<<setprecision(2)<<breakfast<<"��"<<endl;begingin();break; 
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
	printf("----- ҹ���˵� -----\n");
    printf(" 1. ��⽣�2.50\n");
    printf(" 2. �ڱ���1.00\n");
    printf(" 3. �輦����0.60\n");
    printf(" 4. ��������3.50\n");
    printf(" 0. ѡ�����\n");
    printf("������ѡ�");
    cin>>k;
     if((k<5)&&(k>=0))
    coutdinner(k);
    else
    ye();
  
}
void coutdinner(int k)
{
	switch(k){
		case 1:cout<<"�������������";caldinner(1);break; 
		case 2:cout<<"�����ڱ�������";caldinner(2);break; 
		case 3:cout<<"����輦��������";caldinner(3);break; 
		case 4:cout<<"���뼦����������";caldinner(4);break; 
		case 0:cout<<"ҹ���ϼƣ�" <<fixed<<setprecision(2)<<dinner<<"��"<<endl;begingin();break; 
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
