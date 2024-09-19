#include<iostream>
using namespace std;
int main()
{
	char ch;
	int countE=0,countA=0,countI=0;
	cin>>ch;
	while(ch!='.')
	{
	switch(ch){
		case 'E':case 'e':countE++;break;
		case 'A':case 'a':countA++;break;
		case 'I':case 'i':countI++;break;
		default:cout<<"error"<<endl;break;
	}
	cin>>ch;	
	}
	
	cout<<countE<<endl;
	cout<<countA<<endl;
	cout<<countI<<endl;
}
