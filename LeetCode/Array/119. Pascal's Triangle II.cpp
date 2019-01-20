class Solution {
public:
    vector<int> getRow(int rowIndex) {
       
        //应该直接输出，这样做开销有点大,题目要求用O(K)，那么空间不要太大。
        //全部初始化为0
        vector<int> tra(rowIndex+1, 0);
        tra[0] = 1;
        for(int i = 1; i < rowIndex + 1;i++)
        {
            for(int j = i; j >= 1; j--)
                //从后面累加，每次最后一个值都是0+1，然后1+1依次类推。 
                tra[j] += tra[j-1];
        }
        return tra;
    }
};