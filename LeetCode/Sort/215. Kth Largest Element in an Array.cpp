// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         //经典题目，找数组中第k大的数？先排序然后输出第k个肯定是不行的，如果面试官要求是很大的数？
//         sort(nums.begin(), nums.end());
//         return nums[nums.size() - k];
//         //这个方法肯定不行，正确的方法是用快排思想
//     }
// };

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0, right = nums.size() - 1;
        //快排循环
        while (true) {
            //每次求该数在数组中正确的位置，因为快排每次排序的时候其中枢都是正确的位置，如果正好是在k-1的位置那么直接返回这个值，不用将数组完全排序好。然后如果pos的值大于k，那么调整边界位置，将剩下的进行排序，另外一边的就不用管了。因为中枢的值右边肯定都大于中枢，左边都都小于中枢
            int pos = partition(nums, left, right);
            if (pos == k - 1) return nums[pos];
            else if (pos > k - 1) right = pos - 1;
            else left = pos + 1;
        }
    }
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[left], l = left + 1, r = right;
        while (l <= r) {
            if (nums[l] < pivot && nums[r] > pivot) {
                swap(nums[l++], nums[r--]);
            }
            if (nums[l] >= pivot) ++l;
            if (nums[r] <= pivot) --r;
        }
        swap(nums[left], nums[r]);
        return r;
    }
};

//堆排序
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //堆排序实现
        int len = nums.size();
        for(int i = (len/2 - 1);i >=0;--i)
        {
            adjustHeap(nums, len, i);
        }
        for(int j = (len - 1); j >= 0;--j)
        {
            //每次把最后一个数和堆顶交换，然后进行建堆。
            swap(nums[0], nums[j]);
            adjustHeap(nums, j, 0);
        }
        for(int i = 0 ; i < nums.size();i++)
        {
            cout << nums[i] << endl;
        }
        return nums[len - k];
        
    }
    
    void adjustHeap(vector<int>& nums, int len, int i)
    {
        int temp = nums[i];
        for(int k = i*2 + 1; k < len; k = k*2 + 1)
        {
            if(k + 1 < len && nums[k] > nums[k+1])
                k++;
            if(nums[k] < temp)
            {
                nums[i] = nums[k];
                i = k;
            }
            else
                break;
        }
        nums[i] = temp;
    }
};


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        //用快排，自己写一下。主要是这个要从大到小排序
        int left = 0, right = nums.size() - 1;
        //因为题目说k是在1到n的区间内，所以死循环也是可以的。
        while(1)
        {
            int pos = partition(nums, left, right);
            if(pos == k - 1)
                return nums[pos];
            //pos在k的右边，要缩减左边
            else if(pos > k - 1)
            {
                right = pos - 1;
            }
            else
                left = pos + 1;
        }
    }
    int partition(vector<int>& nums, int low, int high)
    {
        //还是这个快排好记一点
        int pivotKey = nums[low];
        while(low < high){
            while(low < high && nums[high] <= pivotKey)
                high--;
            swap(nums[low], nums[high]);

            while(low < high && nums[low] >= pivotKey)
                low++;
            swap(nums[low], nums[high]);
        }
        return low;

    }
};