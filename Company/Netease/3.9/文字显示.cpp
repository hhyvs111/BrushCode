#include<iostream>
#include<cstdio>
#include<cctype>
#include<string>
using namespace std;
int main()
{
	int n;
	scanf("%d", &n);
	while(n--)
	{
		int x, y;
		//x 为字符宽度
		string str;
		scanf("%d %d", &x, &y);
		cin >> str;
		int ans = 0;
		// cout << str <<endl;
		int maxWidth = y;
		for(int i = 0 ;i < str.size();)
		{
			
			//换行符
			// cout << str[i] << endl;
			if(!isalpha(str[i]) && str[i]!= '\\')
			{
				ans = -1;
				break;
			}
			// if(str[i] == '\\' && str[i+1] == 'n')
			// {
			// 	// ans++;
			// 	i += 2;
			// 	continue;
			// }
			int cnt = 0;
			int num = y / x;
			while(num--)
			{
				// cout << " " << str[i] << endl;
				//换行符有几种情况，第一种在开头，那么下一次maxwidth - 1
				if(str[i] == '\\' && str[i+1] == 'n')
				{
					// ans++;
					i += 2;
					if((y/x) == 1)
						continue;
					else if(num != (y/x - 1))
					{
						ans++;
						break;
					}

				}
				else 
				{
					i++;

				}
				if(!num || i == str.size())
				{
					// cout << "         " << ans << endl;
					ans++;
					break;
				}
			}
			


		}
		if(ans == -1)
			printf("impossible\n");
		else
			printf("%d\n", ans);


	}
}