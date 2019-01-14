class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int i = 0, j = A.size() - 1;
        //快排思想
        while(i < j)
        {
            if(A[i] % 2 > A[j] % 2)
            {
                int tmp = A[i];
                A[i] = A[j];
                A[j] = tmp;
            }
            
            if(!(A[i] % 2)) i++;
            if(A[j] % 2) j--;
        }
        return A;
    }
};

/* 
思路：
从头（i）和尾（j）分别遍历数组，若i是奇数，j是偶数，那么交换值。他们在数组中的相对位置就已经正确。
如果i一直是奇数，而j也一直是奇数，那么j动i不动，直到二者可以交换位置。
时间复杂度为O(N)，空间复杂度为O(1)。
