class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //阿里原题啊尼玛，但是改动了一下，这里的是加起来等于0，那么负数也是可以。原来的那个通用解法是不行了，会栈溢出不知道什么情况，估计是递归太多层了。这个题应该不是用这个方法， 应该需要弄一下这个
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        //固定两个数，然后找一个数是否相等为0。同时要判断数是否重复，如果重复直接跳过。
        
        //如果为空，或者最后一个值小于0、第一个值大于0。这种情况是没有解的。
        if (nums.empty() || nums.back() < 0 || nums.front() > 0) return {};
        for(int k = 0; k < nums.size();k++)
        {
            //如果第一个数就大于0了，那么后面的肯定也是大于0的，可以直接跳出了
            if(nums[k] > 0)
                break;
            //相等则直接跳过，达到去重的效果
            if(k > 0 && nums[k] == nums[k - 1])
                continue;
            //用0减去fix的数得到一个target，然后再找到两个数之和等于target即可。
            int target = 0 - nums[k];
            //类似二分，一个从头，一个从尾开始扫。如果和小于target，左边加1。如果和大于target，将右边减减，使和小一点，。
            int i = k + 1, j = nums.size() - 1;
            while(i < j)
            {
                if(nums[i] + nums[j] == target)
                {
                    // vector<int> now (3,0);
                    // now[0] = nums[k];
                    // now
                    ans.push_back(vector<int> {nums[k], nums[i], nums[j]});
                    while(i < j && nums[i] == nums[i + 1]) ++i;
                    while(i < j && nums[j] == nums[j - 1]) --j;
                    //去重完毕后还要左右移动一下
                    ++i;
                    --j;
                }
                else if (nums[i] + nums[j] < target) 
                    ++i;
                else
                    --j;
              
                //上面两个是去重效果
                
            }
        }
            return ans;
        
    }
        
};