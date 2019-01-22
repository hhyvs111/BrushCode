class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1;
        int k = m + n - 1;
        // cout << i << j << k <<endl;
        while(i >= 0 && j >= 0)
        {
            //如果1的值大于2的值，那么把这个值放后面
            nums1[k--] = nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];

        }
        //还剩下2的值，那么直接填完
        while( j >= 0)
            nums1[k--] = nums2[j--];
    }
};
//这道题很有意思，必会！