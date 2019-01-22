class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        //碰到山峰就不能走了
        int N = A.size();
        int i = 0;
        while(i + 1 < N && A[i] < A[i+1])
            i++;
        if(i == 0 || i == N - 1)
            return false;
        while(i + 1 < N && A[i] > A[i+1])
            i++;
        return i == N-1;
        //很精妙的解法，就是走一个山峰，如果碰到顶了就不能走了。
    }
};