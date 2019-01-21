class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        //就是找到一个值，它的右边总和等于左边的总和
        int size = nums.size();
        int sum = 0;
        //不用计算第一个值，这个值是指标
        for(int i = 1;i < size;i++)
        {
            sum+=nums[i];
        }
        int sumLeft = 0;
        int sumRight = sum;
        for(int i = 0 ; i < size;i++)
        {
            //就是找到一个点，能让两边都相等。
            //直接算总值，然后一边加一边减，直到值相等。不用计算中间那个值
            if(sumLeft == sumRight)
                return i;
            sumLeft += nums[i];
            sumRight -= nums[i+1];
        }
        return -1;
    }
};