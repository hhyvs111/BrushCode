class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //去重，然后不能用这个额外的空间，那么两个指针
        int len = nums.size();
        if(len < 1)
            return 0;
        int j = 1;
        int cnt = 0;
        int val = nums[0];
        for(int i = 1;i < len;i++)
        {
            //如果这个值于上一个值相等，那么直接忽略，如果不等则当前数组j位置等于这个值
            if(nums[i] != val)
            {
                nums[j++] = nums[i];
            }
            else
                cnt++;
            val = nums[i];
        }
        return len - cnt;
    }
    //牛逼的解法
    // int count = 0;
    // for(int i = 1; i < n; i++){
    //     if(A[i] == A[i-1]) count++;
    //     else A[i-count] = A[i];
    // }
    // return n-count;
};