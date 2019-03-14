class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //二分查找的2d实现？
        //肯定是不能一个个找的，这样的话是O(N^2)
        //两边一起走，如果都碰壁那么就从1，1的位置继续走
        
//         int m = matrix.size();
//         if(m == 0) return false;
//         int n = matrix[0].size();
//         int i = 0, j =0;
//         //这样太慢了，不行啊，时间效率太低。
        
//         while(i < m && j < n)
//         {
//             //left to right
//             for(int level = j; level < n;level++)
//             {
//                 if(matrix[i][level] == target)
//                     return true;
//                 if(matrix[i][level] > target)
//                     break;
//             }
//             for(int down = i; down < m; down++)
//             {
//                 if(matrix[down][j] == target)
//                     return true;
//                 if(matrix[down][j] > target)
//                     break;
//             }
//             i++;
//             j++;
//         }
        //从矩阵的右上角开始搜，如果比目标数大，那么就右移，如果比目标数小的下移。
        //因为矩阵保证从左至右是递增的，从上到下也是。
        int m = matrix.size();
        if (m == 0) return false;
        int n = matrix[0].size();

        int i = 0, j = n - 1;
        //如果当前数大于目标值，那么第n-1列都大于它，就不用考虑了。依次进行。
        while (i < m && j >= 0) {
            if (matrix[i][j] == target)
                return true;
            else if (matrix[i][j] > target) {
                j--;
            } else 
                i++;
        }
        return false;    
        
    }
};