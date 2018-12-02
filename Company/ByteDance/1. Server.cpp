#include<iostream>
using namespace std;

int main()
{

	//分别代表1u，2u和4u的机器的台数
	int c1, c2, c4;
	//总机架单位
	int n;
	while( cin >> c1 >> c2 >> c4 >> n)
	{
		//隔热层
		int gap = 2;
		int serverNum = 0;
		//直接减去两个机位
		n -= gap;
		while( n > 1)
		{
			if( (c1 == 0) && (c2 == 0) && (c4 == 0) )
				break;
			if(n > 4 && c4 > 0)
			{
				c4--;
				//每次减去一个gap和所占机位
				n -= 5;
				serverNum++;
			}
			else if(n > 2 && c2 > 0)
			{
				c2--;
				n -= 3;
				serverNum++;
			}
			else if(n  > 1 && c1 > 0)
			{
				c1--;
				n -= 2;
				serverNum++;
			}
			gap = serverNum + 1;
			
		}
		cout << serverNum << endl;
	}
	return 0;
}