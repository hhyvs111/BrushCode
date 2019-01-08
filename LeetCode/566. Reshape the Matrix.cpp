class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        
        //重塑矩阵,不要计算错了
        int size_col = nums[0].size();
        int size_row = nums.size();
        
        //如果行列结果不一样，则直接返回原矩阵
        if(r*c != size_col * size_row)
            return nums;
        
        vector<vector<int>> news(r, vector<int>(c, 0));
        
        //这个用来计数
        int col_index = 0, row_index = 0;
        //主要是这个行，如果行比较少，那么直接下一个
        for(int i = 0;i < r;i++)
            for(int j = 0; j < c;j++)
            {
                news[i][j] = nums[row_index][col_index];
                if(col_index < size_col - 1)
                    col_index++;
                else 
                {
                    col_index = 0;
                    row_index++;
                }
            }
        //这个循环有点牛批，看起来简洁很多，但是计算是不是有点多？
        // for (int i = 0; i < r * c; i++)
        //     news[i/c][i%c] = nums[i/n][i%n];
        return news;
    }
    
};