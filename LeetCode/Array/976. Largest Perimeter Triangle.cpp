bool cmp(int i,int j)
{
    return i > j;
}
class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        //找到这个vector里的最长的三角形？当然要满足任意两边相加大于第三边。
        //思路可以排序一下，然后找最大的
        sort(A.begin(),A.end(), cmp);
        int size = A.size();
        //当然也可以从小到大
        for(int i = 0; i < size - 2;i++)
        {
            
            if(A[i] < A[i+1] + A[i+2])
                return A[i] + A[i+1] + A[i+2];
        }
        return 0;
    }
};
