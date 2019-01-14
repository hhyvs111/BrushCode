class Solution {
public:
    //题目的意思是下标是奇数，对应的值也是奇数；
    vector<int> sortArrayByParityII(vector<int>& A) {
        int i = 1, j = 0;
        int size = A.size();
        //i扫奇数，j扫偶数，如果都不对则交换，这里只需要j小于size就好了，因为i后面会溢出
        for(int i = 0, j = 1; i < size;i+=2,j+=2)
        {
            while(i < size && (A[i] % 2 == 0)) i+=2; 
            while(j < size && (A[j] % 2 == 1)) j+=2; 
            //如果i对应都不是偶数则交换，因为这个时候j也不是对应则交换,这里也还要判断不要溢出
            if( (A[i] % 2 == 1) && (A[j] % 2 == 0)  && i < size)
            {
                int tmp = A[i];
                A[i] = A[j];
                A[j] = tmp;
            }
        }
        return A;
    }
};