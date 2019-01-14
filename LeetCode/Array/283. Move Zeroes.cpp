class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        //定义一个下标
        int lastNoZero = 0;
        int size = nums.size(); 
        for(int i = 0; i < size;i++)
        {
            //这里下标不一样，非0的才放入nums[0]的位置
            if(nums[i] != 0)
                nums[lastNoZero++] = nums[i];
           
        }
        //等非0元素都存入了nums,这时需要把0再放到后面
        for(int i = lastNoZero;i < size;i++)
            nums[i] = 0;
    }
};