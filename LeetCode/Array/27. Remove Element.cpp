class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size() < 1)
            return 0;
        //既然不需要在意数组的顺序，那么先排个序
        sort(nums.begin(), nums.end());
        int size = nums.size();
        int begin = -1,end = -1;
        for(int i = 0;i < nums.size();i++)
        {
            if(nums[i] == val)
            {
                if(begin == -1)
                    begin = i;
                end = i;
                size--;
            }
        }
        //当数字不相等都时候才erase
        if(size != nums.size())
            nums.erase(nums.begin() + begin, nums.begin() + end + 1);
        return size;
        //牛逼的解法，这个不用管这个后面的元素？判题应该就是输出return的长度的nums数组。两个指针
        // int i = 0;
        // for (int j = 0; j < nums.length; j++) {
        // if (nums[j] != val) {
        //     nums[i] = nums[j];
        //     i++;
        // }
    }
    }
};