#include <unordered_map>

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        //题目大意：找到出现最多的数字，然后求包含这些数字的最小长度的子串。
        
        //统计数组中元素的个数，即出现的次数
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<nums.size();i++) mp[nums[i]].push_back(i);
        
        //找到出现次数最多的数字
        int degree=0;
        for(auto it=mp.begin();it!=mp.end();it++) degree=max(degree,int(it->second.size()));
        int shortest=nums.size();
        //找到这个数字在数组中第一次出现和第二次出现的位置
        int begin,end;
        for(auto it = mp.begin();it != mp.end();it++)
        {
            //second就是这个vector
            if(it->second.size()==degree)
            {
                //second.back就是最后一个数字的指针，second[0]就是第一个数字的位置
                shortest=min(shortest,it->second.back()-it->second[0]+1);
            }
        }
        return shortest;
        //这个题还是利用了这个unordered_map，无序map，然后用vector作为第二个值，nums[i]为frist值，当都是一样的值时将位置插入到同一值对应的vector
    }
};