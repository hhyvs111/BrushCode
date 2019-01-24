class Solution {
public:
    int thirdMax(vector<int>& nums) {
        //这个方法不是很好，没有达到o(n)
        //set自动排序
        set<int> st(nums.begin(), nums.end());
        //set是从大到小？
        // cout << st.size() << endl;
        auto it = st.end();
        
        if(st.size() < 3)
        {
            //Increments given iterator it by n elements.
            //If n is negative, the iterator is decremented
            advance(it, -1);
            return *it;
        }
            
        else
        {
            advance(it, -3);
            return *it;
        }
        //这个方法不错，就是设置三个最大数，a是最大的，b是第二大的，c是第三大的
    //          long long a, b, c;
    // a = b = c = LLONG_MIN;
    // for (auto num : nums) {
    //     if (num <= c || num == b || num == a) continue;
    //     c = num;
        //如果c比b大则交换
    //     if (c > b) swap(b, c);
        //如果b比a大则交换
    //     if (b > a) swap(a, b);
    // }
    // return c == LLONG_MIN ? a : c;
    }
};