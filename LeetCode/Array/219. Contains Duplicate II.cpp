class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(nums.size() < 1)
            return false;
        set<int> cand;
        for (int i = 0; i < nums.size(); i++) {
            //
            if (i > k) cand.erase(nums[i-k-1]);
            //insert返回的是一个std::pair(it,bool),如果已经有这个数了，那么插入就失败，则if的值是true，
            if (!cand.insert(nums[i]).second) return true;
        }
        return false;
        //找到相等的两个值，看他们的差是多少
//         for(int i = 0 ; i < nums.size() - 1;i++)
//             for(int j = i + 1;j < nums.size();j++)
//             {
//                 if(nums[i] == nums[j] && j - i <= k)
//                 {
//                     cout << j - i << endl;
//                     return true;
//                 }
                    
//             }
        // return false;
    }
};

//有时候还是要会用stl解决问题！