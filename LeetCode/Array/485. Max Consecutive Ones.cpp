class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        //找到连续的1
        int max = 0;
        int cons = 0;
        for(int i : nums)
        {
            //如果是0则清空
            if(i == 0)
                cons = 0;
            else
                cons++;
            //如果连续的大于这个max，则max为cons
            if(cons > max)
                max = cons;
        }
        return max;
    }
};