class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int sumA = 0;
        for(int i : A)
            sumA += A[i];
        int sumB = 0;
        for(int i : B)
            sumB += B[i];
        //求差值的平均值
        int dif = (sumA - sumB) / 2;
        
        //在A中找到一个数，减去这个数后能相等，则是答案
        for(auto it:A){
            if(find(B.begin(), B.end(), it - dif) != B.end() )
                return {it, it-dif};
        }
        return {}; //一般是不会跑到这里来的
    }
    //还是要多学习一下stl的用法，不然真的是太菜了。
};