// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         //经典题目，找数组中第k大的数？先排序然后输出第k个肯定是不行的，如果面试官要求是很大的数？
//         sort(nums.begin(), nums.end());
//         return nums[nums.size() - k];
//         //这个方法肯定不行，正确的方法是用快排思想
//     }
// };

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0, right = nums.size() - 1;
        //快排循环
        while (true) {
            //每次求该数在数组中正确的位置，因为快排每次排序的时候其中枢都是正确的位置，如果正好是在k-1的位置那么直接返回这个值，不用将数组完全排序好。然后如果pos的值大于k，那么调整边界位置，将剩下的进行排序，另外一边的就不用管了。因为中枢的值右边肯定都大于中枢，左边都都小于中枢
            int pos = partition(nums, left, right);
            if (pos == k - 1) return nums[pos];
            else if (pos > k - 1) right = pos - 1;
            else left = pos + 1;
        }
    }
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[left], l = left + 1, r = right;
        while (l <= r) {
            if (nums[l] < pivot && nums[r] > pivot) {
                swap(nums[l++], nums[r--]);
            }
            if (nums[l] >= pivot) ++l;
            if (nums[r] <= pivot) --r;
        }
        swap(nums[left], nums[r]);
        return r;
    }
};