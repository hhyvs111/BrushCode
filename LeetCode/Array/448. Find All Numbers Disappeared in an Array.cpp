class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        //定义一个数组，从1到size的，如果有则加1
        int size = nums.size();
        vector<int> numsCnt;
        for(int i = 0 ;i < size + 1;i++)
            numsCnt.push_back(0);
        for(int i = 0; i < size;i++)
            numsCnt[nums[i]]++;
        vector<int> ans;
        //这里0直接过滤
        for(int i = 1; i < size + 1;i++)
        {
            if(numsCnt[i] == 0)
                ans.push_back(i);
        }
        return ans;
    }
};