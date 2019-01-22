class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sumMax = 0.0;
        for(int i = 0;i < k;i++)
            sumMax += nums[i];
        // cout << sumMax << endl;
        double sumNow = sumMax;
        for(int i = 1; i < nums.size() - k + 1;i++)
        {
            sumNow -= nums[i-1];
            sumNow += nums[i+k-1];
            sumMax = max(sumMax, sumNow);
            // cout << sumMax << endl;
        }
        return sumMax / k;
    }
};

//滑动窗口的题，比较简单