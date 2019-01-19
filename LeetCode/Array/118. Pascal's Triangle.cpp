class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        //初始化都为0
        for(int i = 0;i < numRows;i++)
        {
            //重新初始化为长度
            ans[i].resize(i + 1);
            //第一个和最后一个都是0
            ans[i][0] = ans[i][i] = 1;
            for(int j = 1; j < i;j++)
            {
                ans[i][j] = ans[i-1][j-1] + ans[i-1][j];
            }
        }
        return ans;
    }
};