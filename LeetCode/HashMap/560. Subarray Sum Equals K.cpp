class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0, sum = 0, n = nums.size();
        unordered_map<int, int> m{{0, 1}};
        //这里主要是看这个map，如果sum-k存在说明这个序列的和等于k，然后每次sum都存入map里。等到下一次再次遇到sum-k有值时，说明又有序列等于k
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            cout << sum << endl;
            res += m[sum - k];
            cout << m[sum - k] << endl;
            ++m[sum]; 
        }
        return res;
    }
};