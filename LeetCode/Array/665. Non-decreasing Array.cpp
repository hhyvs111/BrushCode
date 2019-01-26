class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        //非递减数组，那么就是递增或者相等咯。看判断是否有一个凹的，有点类似一个其他的题。
        //思路
        //碰到有问题的地方，主要是一个改变i还是改变i-1的值。这是一个贪心法处理规则
        //当nums[i - 1] > nums[i]，这个时候要判断i-1的前序i-2是什么值，主要是保证i前面的序列为一个非递减的序列
        //如果nums[i-2] <= nums[i],那么这个时候nums[i - 1] = nums[i]可以使i前面的序列正确
        //如果nums[i-2] > nums[i],那么就要改变nums[i]的值，使其等于nums[i-1]，使i前面序列正确
        
        int cnt = 0;
        for(int i = 1 ; i < nums.size();i++)
        {
            if(nums[i - 1] > nums[i])
            {
                cnt++;
                //这里为什么要判断这个i-2 < 0，1是为了防止越界，2是如果i=2出现波动，基于贪心法原则，肯定是将i-1变小是最佳选择。比如1，4，2，3。这里当然要把4变为1比较好，如果2变为4，尽量往小变是最好的。
                if(i - 2 < 0 || nums[i-2] <= nums[i]) 
                    nums[i-1] = nums[i];
                else
                    //
                    nums[i] = nums[i-1];
            }
            
        }
        return cnt <= 1;
        
        //解法二
        //就是当出现这个问题值时，也是两种情况，将nums[i-1] = nums[i]时，判断是否有序
        //如果还是无序，那么将nums[i] = nums[i - 1],再次判断。这里要用一个temp存nums[i-1]的值。
        class Solution {
        public:
            bool checkPossibility(vector<int>& nums) {
                for (int i=1; i < nums.size(); i++){
                    if (nums[i-1]<=nums[i]) continue;
                    int temp=nums[i-1];
                    nums[i-1]=nums[i];
                    if (is_sorted(nums.begin(),nums.end())) return true;
                    nums[i-1]=nums[i]=temp;
                    return is_sorted(nums.begin(),nums.end());
                }
                return true;
            }
        };
       
//         int size = nums.size();
//         int i = 0;
//         bool incre = false;
        
//         while(i + 1 < size && nums[i] <= nums[i+1])
//         {
//             if(nums[i] < nums[i+1])
//                 incre = true;
//             i++;
//         }
//         cout <<"first " << i << endl;
//         if(i < size - 1 && nums[i] > nums[i+1])
//         {
//             if(!incre)
//                 nums[i] = nums[i+1];
//             else
//                 nums[i+1] = nums[i];
//             cout << "nums " << nums[i] << " " << nums[i + 1] << endl;
//         }
//         else if(i == size - 1 && nums[i] < nums[i - 1])
//             return true;
//         cout <<"second " << i << endl;
//         while(i + 1 < size && nums[i] <= nums[i+1])
//             i++;
//         cout <<"end " << i << endl;
//         return i == size - 1;
            
//             return true;
//         //最后一个是可以改变的
//         else if (i == size - 2)
//         {
//             if(nums[i] >= nums[i+1])
//                 return true;
//         }
//         //开头，而且这个第二个值小于3，也就是2以上，这样才能变为1使数组递增
//         else if(i == 0)
//         {
//             if(nums[i+1] < 3)
//             {
//                 i++;
//                 while(i + 1 < size && nums[i] <= nums[i+1])
//                     i++;
//             }
               
//         }
//         else
//         {
//             if(nums[i + 1]  - nums[i - 1] > 1)
//             {
//                 i++;
//                 while(i + 1 < size && nums[i] <= nums[i+1])
//                     i++;
//             }
                
//         }
//         cout << i << endl;
//         return i == size - 1;
    }
};