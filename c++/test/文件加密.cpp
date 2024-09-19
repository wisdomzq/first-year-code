#include<iostream>
#include<fstream>
using namespace std;
struct mm{
	char in, out;
};
int main()
{
	int line = 0;
	mm sj[1000];
	string mmb, file;
	char buff[100];
	cin >> mmb >> file;
	ifstream ifs;
	ifs.open("D:\\code\\c++\\test\\mima0.txt");
	if (!ifs.is_open())
{
	cout << "fail" << endl;
	return 0;
}
	while (ifs.getline(buff,sizeof(buff)))
	{
		sj[line].in = buff[0];
		sj[line].out = buff[2];
		line++;
	}
	ifs.close();

	ifs.open("D:\\code\\c++\\test\\file0.txt");
	if (!ifs.is_open())
{
	cout <<" fail" << endl;
	return 0;
}
	while (ifs.getline(buff, sizeof(buff)))
	{
		for (int i = 0; i < sizeof(buff); i++)
		{
			if (buff[i] == '\n' || buff[i]=='.')break;
			for (int j = 0; j < line; j++)
			{
				if (buff[i] == sj[j].in)
				{
					buff[i] = sj[j].out;
					break;
				}
			}
		}
		cout << buff << endl;
	}
	ifs.close();
}