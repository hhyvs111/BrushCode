class Solution {
public:
    void sortColors(vector<int>& nums) {
        //用常空间，one pass排序，one pass
        //定义三个数字，分别为low和mid和high。既然0 1 2 顺序固定，那么low就专门指向0，high专门指向2，当mid扫到0的时候将值与low指向的值交换，然后low++，因为这个时候0已经去了它该去的位置，同理mid扫到2的时候将其与high交换
        int low = 0, mid = 0, high = nums.size() - 1;
        //这里因为high是正确才会向前走
        while(mid <= high)
        {
            if(nums[mid] == 1)
            {
                mid++;
            }
            else if(nums[mid] == 0)
            {
                swap(nums[mid], nums[low]);
                low++;
                mid++;
            }
            else
            {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
        
    }
};