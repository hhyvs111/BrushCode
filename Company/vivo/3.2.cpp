#include<bits/stdc++.h>

using namespace std;

/**
* Welcome to vivo
*/

#define MAX_NUM 101

int solution(int n, vector<int>& nums) {
    // cout << nums.size() << endl;
    // cout << n << endl;
	int sum = 0;
	for(int i = 0;i < n;i++) {
		sum+= nums[i];
	}

	sort(nums.begin(), nums.end());
	vector<vector<int>> f(n + 1, vector<int> (sum/2 + 1));
	for(int i = 0;i < n;i++) {
		for(int j = 1;j <= sum/2;j++) {
			f[i+1][j] = f[i][j];
			if(nums[i] <= j && f[i][j - nums[i]] + nums[i] > f[i][j])
				f[i+1][j] = f[i][j-nums[i]] + nums[i];
		}
	}
    return sum - 2 * f[n][sum/2];
}

int main()
{    
	string str("");
	getline(cin, str);
	vector<int> a;
	int i = 0;
	char *p;
	int count = 0;
	
	const char* strs = str.c_str();
	p = strtok((char *)strs, " ");
	while(p)
	{
		a.push_back(atoi(p));
		count++;
		p = strtok(NULL, " ");
		i++;
		if(i >= MAX_NUM)
			break;
	}
	
	int result = solution(count, a);
	cout << result << endl;
	return 0;
}