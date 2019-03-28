#include<bits/stdc++.h>
 
using namespace std;
 
void HeapAdjust (vector<int>& data, int k)
{
	int length = data.size();
	int tmp = data[k];
	int i=2*k+1;
	while (i<length) {
		if (i+1<length && data[i]>data[i+1]) //选取最小的结点位置
			++i;
		if (tmp < data[i]) //不用交换
			break;
		data[k] = data[i]; //交换值
		k = i; //继续查找
		i = 2*k+1;
	}
	data[k] = tmp;
}
 
void HeapSort (vector<int>& data)
{
	int length = data.size();
	if (length <= 0)
		return;
	for (int i=length/2-1; i>=0; --i) {
		HeapAdjust(data, length, i); //从第二层开始建堆
	}
 
	for (int i=length-1; i>=0; --i) {
		std::swap(data[0], data[i]);
		//好像这里不对，要传入的是i？那么就是下标的值？看来还是要传入长度了？
		HeapAdjust(data, i, 0); //从顶点开始建堆, 忽略最后一个
	}
 
	return;
}

    void adjustHeap(vector<int>& nums, int i)
    {
        int temp = nums[i];
        int len = nums.size();
        for(int k = i*2 + 1; k < len; k = k*2 + 1)
        {
            if(k + 1 < len && nums[k] < nums[k+1])
                k++;
            if(nums[k] > temp)
            {
                nums[i] = nums[k];
                i = k;
            }
            else
                break;
        }
        nums[i] = temp;
    }
    int findKthLargest(vector<int>& nums, int k) {
        //堆排序实现
        int len = nums.size();
        for(int i = (len/2 - 1);i >=0;--i)
        {
            adjustHeap(nums, i);
        }
        for(int j = (nums.size() - 1); j >= 0;--j)
        {
            //每次把最后一个数和堆顶交换，然后进行建堆。
            swap(nums[0], nums[j]);
            adjustHeap(nums, j);
        }
        for(int i = 0 ; i < nums.size();i++)
        {
            cout << nums[i] << endl;
        }
        return nums[k - 1];
        
    }
    


int main (void)
{
	vector<int> data{49, 38, 65, 97, 76, 13, 27, 49};
	int length = 8;
	HeapSort(data);
	// findKthLargest(data, 2);
	for (int i=0; i<length; ++i) {
		std::cout << data[i] << " ";
	}
 
	std::cout << std::endl;
	return 0;
}
