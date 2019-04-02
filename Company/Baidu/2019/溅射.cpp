#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	while(cin >> n)
	{
		int Max, Min;
		cin >> Max >> Min;
		vector<int> nums;
		for(int i = 0 ; i < n;i++)
		{
			int num;
			cin >> num;
			nums.push_back(num);
		}
		sort(nums.begin(), nums.end());
		int ans = 0;
		while(nums[n - 1] != 0)
		{
			ans++;
			for(int i = n - 1;i >= 0;i--)
			{
				if(i == n - 1)
					nums[i] = nums[i] - Max >= 0 ? nums[i] - Max : 0;
				else
					nums[i] = nums[i] - Min >= 0 ? nums[i] - Min : 0;
			}
			sort(nums.begin(), nums.end());

		}
		cout << ans << endl;
	}
	return 0;
}
//这个题应该不能去排序，没必要去排序，时间复杂度太高。应该找到一个最大的就好，时间复杂度o(n)