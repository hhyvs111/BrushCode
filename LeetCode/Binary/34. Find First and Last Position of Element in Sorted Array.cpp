class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        vector<int> ans = {-1, -1};
        int leftIndex = boundSearch(nums, target, true);
        if(leftIndex == nums.size() || nums[leftIndex] != target)
            return ans;
        ans[0] = leftIndex;
        ans[1] = boundSearch(nums, target, false) - 1;
        return ans;
        //O（logN）那么就只能用二分了？首先可能只能找到一个点，但是怎么找到多个点？难道左右开始遍历？
    //     int left = 0, right = nums.size() - 1;
    //     vector<int> ans{-1,-1};
    //     while(left <= right)
    //     {
    //         int mid = (left + right)/2;
    //         if(nums[mid] == target)
    //         {
    //             cout << mid << endl;
    //             //找到后再左右扫描，怎么好像速度不是很快的感觉。如果这个目标值占总值的很大一部分，那么就会退化为O(n)，这样就达不到题目要求了。
    //             for(int i = mid, j = mid;i >= 0 || j < nums.size() ;i--,j++)
    //             {
    //                 if(i >= 0 && nums[i] == target)
    //                     ans[0] = i;
    //                 if(j < nums.size() && nums[j] == target)
    //                     ans[1] = j;
    //             }
    //             return ans;
    //         }
    //         else if(nums[mid] < target)
    //         {
    //             left = mid + 1;
    //         }
    //         else
    //             right = mid - 1;
    //     }
    //     return ans;
    // }
    }
    
    //这题要用low_bound和upper_bound, 找到第一个比target小的，和找到第一个比target大的。那就是边界值。
    int boundSearch(vector<int>& nums, int target, bool isLeft)
    {
        int left = 0;
        int right = nums.size();
        while(left < right)
        {
            int mid = (left + right)/2;
            //如果left为真就是求左边界，否则就是求右边界
            //这里求右边界就是找到第一个比target大的值，然后返回后再减去-1就是右边界
            //左边界的话就是找到相等的值后还要继续求，看是否mid不等于target，当不等于后left就会走到right的位置，此时就返回，因为right就是指向了左边界。
            if(nums[mid] > target || (isLeft && target == nums[mid]))
            {
                right = mid;
            }
            else
                left = mid + 1;
        }
        return left;
    }
};