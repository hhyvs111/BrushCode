#include<cmath>
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //只能o1，不能修改数字
        // //好像之前有看到说是什么异或，剩下的就是重复的值，但是这里好像不止一个值重复
        // int ans = 0;
        // for(auto i : nums){
        //     ans  = ans & i;
        // }
        //这样，用异或好像算出来的是不对的，注意题目，这里是给了你1到n的数字范围，但是有n+1个数。利用一下这个特点难道是相减？这里的重复数字不止出现2次，可以全是一样的数字
        
        //龟兔赛跑？按value的值跳跃，乌龟走一步，兔子走两步，这里的index是下标
        int tortoise = nums[0];
        int hare = nums[0];
        //先用快慢指针找到相同的值
        do {
            tortoise = nums[tortoise];
            hare = nums[nums[hare]];
        } while (tortoise != hare);
        //然后再次遍历？为什么要再次遍历，测试链表是否有环！这个题很牛逼
        // Find the "entrance" to the cycle.
        int ptr1 = nums[0];
        int ptr2 = tortoise;
        while (ptr1 != ptr2) {
            ptr1 = nums[ptr1];
            ptr2 = nums[ptr2];
        }

        return ptr1;
        // int size = nums.size() - 1;
        // int sumSize = size* (size + 1) / 2;
        // int sum = 0;
        // for(auto i : nums){
        //     sum += i;
        // }
        // return (sum- sumSize);
        
        
        
        //用map的话肯定一下就出来了
        // unordered_map<int, int> dupMap;
        // for(auto i : nums){
        //     dupMap[i]++;
        // }
        // for(auto it : dupMap)
        // {
        //     if(it.second > 1)
        //         return it.first;
        // }
        // return 0;
    }
};

//二分法
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int left = 0, right = nums.size();
        while (left < right){
            int mid = left + (right - left) / 2, cnt = 0;
            for (int num : nums) {
                if (num <= mid) ++cnt;
            }
            if (cnt <= mid) left = mid + 1;
            else right = mid;
        }    
        return right;
    }
};