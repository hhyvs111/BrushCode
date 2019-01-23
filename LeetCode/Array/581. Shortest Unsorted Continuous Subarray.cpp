class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        //找到一个最短子序列，如果这个子序列有序了，那么整个序列就有序了
        //找到第一个值大于前面小于后面，然后找到最后一个类似的值
        
        //一次遍历，左、右同时进行；
            // 左边前进记录当前经过元素的最大值，若按照升序规则，则当前遍历元素即为当前最大值；如果二者不相等，则用j记录当前前进的索引；
            // 右边后退记录当前经过元素的最小值，按照升序规则，则当前遍历元素即为当前最小值；如果二者不相等，则用i记录当前后退的索引。
            // 当一次遍历完成，前进的索引记录了不符合升序规则的最大索引，后退的索引记录了不符合规则的最小索引。

       int n = nums.size(), beg = -1, end = -2, Min = nums[n-1], Max = nums[0];
        for (int i = 1;i < n;i++) {
          Max = max(Max, nums[i]);
          Min = min(Min, nums[n-1-i]);
          if (nums[i] < Max) end = i;
          if (nums[n-1-i] > Min) beg = n-1-i; 
         }
        return end - beg + 1;
        // int firstIndex = -2;
        // int lastIndex = -1;
        // for(int i = 0; i < nums.size() - 1; i++)
        // {
        //     if(firstIndex == -2 && nums[i] > nums[i+1])
        //         firstIndex = i - 1;
        //     //判断这个值是否大于firstIndex
        //     if(nums[i] >= nums[i+1] && nums[i] > nums[firstIndex])
        //         lastIndex = i+1;
        //     cout << firstIndex << " " << lastIndex << endl;
        // }
        // if(firstIndex == -2)
        //     return 0;
        // return lastIndex - firstIndex ;
    }
};