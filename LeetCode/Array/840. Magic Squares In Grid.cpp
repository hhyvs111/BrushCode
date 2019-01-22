class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        //找到一个矩阵，这个矩阵满足都有1-9的数字，而且满足对角线和十字的值都相等。
        int rowSize = grid.size();
        int colSize = grid[0].size();
        int ans = 0;
        for(int i = 0; i < rowSize - 2;i++)
            for(int j = 0; j < colSize - 2;j++)
            {
                if(grid[i+1][j+1] != 5)
                    continue;
                //首先定义一个数组
                vector<int> nums(10,0);
                int cnt = 0;
                bool isMagic = true;
                for(int p = j; p < j+3;p++)
                    for(int q = i;q < i+3;q++)
                    {
                        // cout << " test " << grid[q][p] <<endl;
                        if(grid[q][p] > 9)
                            continue;
                        nums[grid[q][p]]++;
                    }
                for(int k = 1; k < 10; k++)
                    if(nums[k] == 0 || nums[k] == 2)
                        isMagic = false;
                // cout << isMagic << endl;
                //还要考虑竖直相加
                if(isMagic && (grid[i][j] + grid[i+1][j+1] + grid[i+2][j+2]) == 
                   (grid[i][j+2] + grid[i+1][j+1] + grid[i+2][j]) && 
                  (grid[i][j+1] + grid[i+1][j+1] + grid[i+2][j+1]) == 
                   (grid[i+1][j] + grid[i+1][j+1] + grid[i+1][j+2]) &&
                 (grid[i][j] + grid[i+1][j] + grid[i+2][j]) == 15 && 
                  (grid[i][j+2] + grid[i+1][j+2] + grid[i+2][j+2]) == 15 && 
                  (grid[i][j] + grid[i][j+1] + grid[i][j+2]) == 15 &&
                  (grid[i+2][j] + grid[i+2][j+1] + grid[i+2][j+2]) == 15)
                    ans++;
            }
        return ans;
    }
    
};

//这道题的话主要是题目的意思没有了解，行列式都等于15才是对的，然后中间必须是5