class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        //找到这里最大的数其他所有数比较，如果都是他们的两倍则返回这个数，怎么在O(N)实现？
        //这个也可以当做是找到两个最大的值，如果这个值是两倍
        int maxNum = -1, maxNumIndex = 0;
        int secondNum = -1;
        
        for(int i = 0 ;i < nums.size();i++)
        {
            if(nums[i] > maxNum )
            {   
                secondNum = maxNum;
                maxNum = nums[i];
                maxNumIndex = i;
            }
            //如果比最大的小，但是比第二大的大
            else if(nums[i] > secondNum)
                secondNum = nums[i];
        }
        if(secondNum * 2 > maxNum)
            return -1;
        
        //那么为之前大找第二大的弄错了，没有判断这个比max小但是比second大的值
        // for(int i = 0; i < nums.size();i++)
        // {
        //     if(i != maxNumIndex)
        //     {
        //         if(nums[i] * 2 > maxNum)
        //             return -1;
        //     }
        // }
        return maxNumIndex;

    }
};