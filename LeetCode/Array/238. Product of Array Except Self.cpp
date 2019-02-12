// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums) {
//         //输出除了自己其他的数的乘积，2*3*4等于24.
//         long long sum = 1;
//         //要排除0啊，尴尬。
//         //标记0的位置，
//         int zero = 0;
//         for(int i = 0 ; i < nums.size(); i++)
//         {
//             if(nums[i] == 0)
//             {
//                 zero++;
//             }
//             else
//             {
//                 sum *= nums[i];
//             }
//         }
//         if(zero > 1)
//         {
//             fill(nums.begin(), nums.end(), 0);
//             return nums;
//         }
//         cout << sum << endl;
//         for(int i = 0 ; i < nums.size(); i++)
//         {
            
//             //如果非空那么代表有0，
//             if(nums[i] == 0)
//                 nums[i] = sum;
//             else if(zero > 0)
//                 nums[i] = 0;
//             else
//                 //不准用除法，尼玛哦我说呢
//                 nums[i] = sum / nums[i];
//             cout << nums[i] << endl;
//         }
//         return nums;
//     }
// };

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> fromBegin(n);
        fromBegin[0]=1;
        vector<int> fromLast(n);
        fromLast[0]=1;
        //对于某一个数字，如果我们知道其前面所有数字的乘积，同时也知道后面所有的数乘积，
        //那么二者相乘就是我们要的结果，所以我们只要分别创建出这两个数组即可，
        //分别从数组的两个方向遍历就可以分别创建出乘积累积数组
        for(int i=1;i<n;i++){
            fromBegin[i]=fromBegin[i-1]*nums[i-1];
            fromLast[i]=fromLast[i-1]*nums[n-i];
        }
        
        vector<int> res(n);
        for(int i=0;i<n;i++){
            res[i]=fromBegin[i]*fromLast[n-1-i];
        }
        return res;
    }
};