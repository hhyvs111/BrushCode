#include<cmath>
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //用set去重
        set<int> setNums (nums.begin(),nums.end());
        return 2*(sum(nums) - sum(setNums));
        //异或操作，最后会等于出现单数的数字
       int singleNumber(int A[], int n) {
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum ^= A[i];
        }
        return sum;
    }
        // int ans;
        // unordered_map<int, int> numsMap;
        // for(int i : nums)
        // {
        //     if(!numsMap.insert({i,0}).second)
        //         numsMap[i]++;
        //     if(numsMap[i] == 0)
        //         ans = i;
        // }
        // for(auto i : numsMap)
        // {
        //     if(i.second == 0)
        //     {
        //         ans = i.first;
        //         break;
        //     }
        // }
        // return ans;
    }
};