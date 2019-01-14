class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        //判断是否单调自增或者递减，那么要看前两个的关系，如果相等则再判断。
        int size = A.size();
        bool des = false;
        bool ins = false;
    
        //找一个差值，这个差值就是这个序列的基础属性
        for(int i = 0;i < size - 1;i++)
        {
            //如果同时存在两种情况则错误
            if(A[i+1] - A[i] > 0) ins = true;
            if(A[i+1] - A[i] < 0) des = true;
            if(ins && des)
                return false;
        }
    
        return true;
    }
};