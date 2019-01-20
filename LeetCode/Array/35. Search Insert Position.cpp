class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        //这里没有重复的数字,可以利用二分查找
        int size = nums.size();
        int left = 0;
        int right = size - 1;
        //这里停在了左端点，0 + 3 = 1;
        int mid = (left + right) /2;
        int initMid = mid;
        while(left <= right)
        {
            if(nums[mid] == target)
            {
                return mid;
            }
            //大于中间的值，往右边找
            else if(nums[mid] < target)
            {
                left = mid + 1;
                
            }
            else
            {
                right = mid - 1;
            }
            mid = (left + right) /2;
        }
        //这里返回left，此时
        return left;
        // if(target > nums[mid])
        //     return mid + 1;
        // return mid;
    }
};