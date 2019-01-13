class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int size_col = matrix.size();
        int size_row = matrix[0].size();
        
        //检查左下的数字，如果一个不一样就直接跳出,最后一列和最后一排不用检查
        for(int i = 0;i < size_col - 1; i++)
            for(int j = 0; j < size_row - 1; j++)
            {
                if(matrix[i][j] != matrix[i+1][j+1])
                    return false;
            }
        return true;
    }
};