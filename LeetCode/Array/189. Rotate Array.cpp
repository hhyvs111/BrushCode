class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        //先用O(N)实现一下
        //利用这个stl把
        
        int size = nums.size();
        vector<int> copy (size);
        for(int i = 0;i < size;i++)
        {
            copy[ (i+k) % size] = nums[i];
        }
        // for(int i = k%size, j = 0; i < size;i++)
        //     copy[i] = nums[j++];
        nums = copy;
        
    }
};

//
// class Solution {
// public:
//     void rotate(vector<int>& nums, int k) {
//         if (nums.empty() || (k %= nums.size()) == 0) return;
//         int n = nums.size();
//         reverse(nums.begin(), nums.begin() + n - k);
//         reverse(nums.begin() + n - k, nums.end());
//         reverse(nums.begin(), nums.end());
//     }
// };