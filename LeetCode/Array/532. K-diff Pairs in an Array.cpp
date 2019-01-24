class Solution {
public:
  int findPairs(vector<int>& nums, int k) {
    if (k < 0) return 0;
    unordered_map<int, int> m;
      //统计相同的数，如果没有则为1
    for (int n : nums) m[n]++;
    int cnt = 0;
    for (auto p : m) {
        //如果k是0，那么只要相同的数就能算一对
      if ((!k && p.second > 1)
          //如果k不等于0，则看k+i是否存在
        || (k && m.count(p.first + k))) ++cnt;
    }
    return cnt;
  }
};
// class Solution {
// public:
//     int findPairs(vector<int>& nums, int k) {
        
//         if(nums.size() < 1)
//             return 0;
//         //给一个数组和k，找到这个数组里差值为k的数组对
//         //暴力是可以但是时间复杂度太大，可以排序一下？
//         sort(nums.begin(), nums.end());
//         int ans = 0;
//         //这里要注意如果是一样都值那么计算是一样的
//         int p = 0;
//         for(int i = 0;i < nums.size() - 1;i++)
//         {
//             if(p && nums[i+1] == nums[i] && k != 0)
//                 continue;
//             int j = 1;
//             //找配对
//             while(j < nums.size() - 1)
//             {
//                 p = 1;
//                 int diff = nums[i+j] - nums[i];
//                 cout << nums[i+j] << " " << nums[i] << endl;
//                 if(diff == k)    
//                 {
                    
//                     ans++;
//                     break;
//                 }
//                 else 
//                     j++;
//             }

//         }
//         return ans;
//     }
// };