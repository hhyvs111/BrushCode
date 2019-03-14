class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //用一个队列维护，不行，这个不能删除数字。然后维护最大值？还是说用优先队列
        //初始化队列，这个肯定不是O（N）但是先试一下。
        if(k == 1)
            return nums;
        vector<int> ans;
        //用双向队列，主要是每次都要求最大值？要在线性时间解决就只能遍历一遍了。
        deque<int> d;

        //用双端队列维护一个降序，但是存的是数组下标而不是数组值
        for(int i = 0 ; i < nums.size();i++)
        {
            //如果队头的数是窗口的左边的值，那么就要将其丢弃
            if(!d.empty() && d.front() == i - k)
                d.pop_front();
            //如果新进来的数比队列尾部大那么就将这个尾部丢弃，直到出现比i大的数。
            while(!d.empty() && nums[d.back()] < nums[i]) 
                d.pop_back();
            d.push_back(i);
            //每次结束后队列就是当前一个降序排列，队头是最大的值。
            //这里为什么要判断是k-1 因为一开始要维护一个k长度的队列，比如k==3，那么就是说要3个数比完后才知道哪个是最大值。
            if(i >= k - 1)
                ans.push_back(nums[d.front()]);
        }        
        return ans;
    }
};