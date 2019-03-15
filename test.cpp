#include<iostream>
#include<vector>
using namespace std;
int main()
{
	long long n;
	cin >> n;
	vector<long long> nums;
	for(int i = 0 ; i < 2 * n;i++)
	{
		long long  num;
		cin >> num;
		nums.push_back(num);
	}
	long long  min = nums[0], max = nums[1];
	for(int i = 0;i < 2 * n;i++)
	{
		if(i%2 == 0)
		{
			if(min > nums[i]) min = nums[i];
		}
		else
			if(max < nums[i]) max = nums[i];
	}
	cout << min << " " << max << endl;
	return 0;
}