class Solution {
public:
    bool canJump(vector<int>& nums) {
        //这个题什么意思啊，好像是说当前所在位置就是你能跳的地方。但是第一个例子好像不是很对啊 ，明明显示的是2怎么跳1步？
        //理解错了，说的是这个跳最大，那么就可以跳1步也可以跳两步。
        //如果用贪心法，那么就是在能跳的区间里选下一个最大的跳，这样尽可能的跳更远。
        
        //贪心法，只用管最左边那个。reach代表能到达的最远的地方，如果i加nums[i]大于reach则reach等于i+nums[i]
        if(nums.empty()) return false;
        int reach = nums[0];
        for(int i = 1; i < nums.size() && reach >= i;i++)
        {
            if(i + nums[i] > reach) 
                reach = i + nums[i];
        }
        if(reach >= nums.size() - 1)
            return true;
        else
            return false;
        
        // int i;
        // for(i = 0; i < nums.size();)
        // {
        //     int jumpSize = nums[i];
        //     if(jumpSize == 0 && i != nums.size() - 1)
        //         return false;
        //     if(i + jumpSize >= nums.size() - 1)
        //         return true;
        //     int maxJump = 0;
        //     int maxJumpIndex = i;
        //     for(int j = i + 1;j < i + jumpSize - 1 && j < nums.size();j++)
        //     {
        //         if(nums[j] > maxJump)
        //         {
        //             maxJumpIndex = j;
        //             maxJump = nums[j];
        //         }
        //     }
        //     i = maxJumpIndex;
        //     cout << maxJumpIndex << endl;
        // }
        // if(i == nums.size() - 1)
        //     return true;
        // else
        //     return false;
    }
};