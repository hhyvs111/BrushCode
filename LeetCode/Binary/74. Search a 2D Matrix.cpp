class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if(m == 0) return false;
        int n = matrix[0].size();
        //用矩阵二分法
        int left = 0;
        int right = n*m -1;
        //因为存在如下属性，他们都是有序的，那么我们可以将其看做是一个一维数组，就是第二行接到第一行以此类推。那么第k个数就是matrix[k/n][k%n];
        while(left <= right)
        {
            int mid = (left + right)/2;
            int now = matrix[mid/n][mid%n];
            if(target == now)
            {
                return true;
            }
            else if(target > now)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return false;
    }
};