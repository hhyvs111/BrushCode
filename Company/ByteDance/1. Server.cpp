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
		while( (n - gap ) > 0)
		{
			if((n + gap) > 4 && c4 > 0)
			{
				c4--;
				n -= 4;
				serverNum++;
			}
			else if((n + gap) > 2 && c2 > 0)
			{
				c2 --;
				n -=2;
				serverNum++;
			}
			else if((n + gap ) > 1 && c1 > 0)
			{
				c1--;
				n--;
				serverNum++;
			}
			gap = serverNum + 1;
			
		}
		cout << serverNum << endl;
	}
	return 0;
}