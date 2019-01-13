class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        //直接求原来的行列长度
        int size_row = A[0].size();
        int size_col = A.size();
        
        //初始化不要搞反了。
        vector<vector<int>>  B(size_row, vector<int>(size_col, 0));
        
        for(int i = 0;i < size_col;i++)
        {
            for(int j = 0; j < size_row;j++)
            {
                B[j][i] = A[i][j];
            }
        }
        return B;
    }
};