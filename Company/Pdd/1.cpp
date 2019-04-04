#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> nums;
    for(int i = 0;i < n;i++){
        int num;
        cin >> num;
        nums.push_back(num);
    }
    sort(nums.begin(), nums.end());
    int lastSum = nums[0] + nums[n-1];
    vector<int> sumNums;
    for(int i = 0; i < n/2;i++){
        sumNums.push_back(nums[i] + nums[n - i - 1]);
    }
    sort(sumNums.begin(),sumNums.end());
    cout << sumNums[n/2 - 1] - sumNums[0] << endl;

    return 0;
}