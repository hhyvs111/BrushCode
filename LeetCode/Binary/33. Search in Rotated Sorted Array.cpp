// class Solution {
// public:
//     int search(vector<int>& nums, int target) {
//         //在旋转排序数组里找，这样就用不了二分了？看题目相关还是用二分，估计是这个用磨二分
//         //得先找到第一个不相等的值吧，才能用二分？这个找的
//         int n = nums.size();
//         int left = 0, right = n - 1;
//         //找到边界
//         int mid;
//         while(left < right)
//         {
//             mid = (left + right) / 2;
//             if(nums[mid] > nums[right])
//             {
//                 left = mid + 1;
//             }
//             else
//                 right = mid;
//         }
//         int rMid = left;
//         cout << rMid << endl;
//         left = 0;
//         right = n - 1;
//         while(left <= right)
//         {
//             int fakeMid = (left + right) / 2;
//             int realMid = (fakeMid + rMid) % n; 
//             if(nums[realMid] == target)
//             {
//                 return realMid;
//             }
//             else if(nums[realMid] > target)
//             {
//                 left = fakeMid + 1;
//             }
//             else
//                 right = fakeMid - 1;
//         }
//         return -1;
        
//     }
// };

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] == target) return mid;
            //如果中间值小于右边的值，则右边是有序的了，这里不是先和target比
            else if (nums[mid] < nums[right]) {
                //如果值比目标值小，且右边的值比目标值大大于目标，那么将搜索范围缩小到右边，否则缩小到左边。这里注意这个nums[right] 大于target，target肯定在这边，因为这边是有序的。
                if (nums[mid] < target && nums[right] >= target) left = mid + 1;
                else right = mid - 1;
            } else {
                if (nums[left] <= target && nums[mid] > target) right = mid - 1;
                else left = mid + 1;
            }
        }
        return -1;
    }
};