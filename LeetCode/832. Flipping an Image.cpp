class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        //简单来说就是列对称互换，然后取相反数，应该是对称矩阵
        int size = A.size();
        for(int i = 0;i < size;i++)
        {
            for(int j = 0; j < size / 2; j++)
            {
                int tmp = !A[i][j];
                A[i][j] = !A[i][size - j - 1];
                A[i][size - j - 1] = tmp;
            }
            //这里单独考虑这个奇数情况，因为上面那个循环走不到这里
            if(size%2)
                A[i][(size/2)] = !A[i][(size/2)];
        }
         return A;
    }
   
};

