#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> threeSum(vector<int>& nums,int targetNum);
vector<vector<int>> function1(vector<int>& nums, int target);
void helper(vector<vector<int>>& ans, vector<int>& combinate, vector<int>& candidates, int start, int target);

    void combination(vector<int>& candidates, vector<int>& combinate, int start, int target, vector<vector<int>>& res)
    {
        //如果为0那么就是成立
        if(!target && combinate.size() == 3)
        {
            res.push_back(combinate);
            return;
        }
        for(int i = start; i < candidates.size() && target >= candidates[i]; ++i)
        {
            combinate.push_back(candidates[i]);
            //这里的是i，因为可以传入自己，上次那个subsets只能传入下一个值，然后还传入了目标值，因为要减去等于0
            combination(candidates, combinate, i, target - candidates[i], res);
            combinate.pop_back();
        }

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        //一看又不会做，也是一个组合值，加上后等于这个目标值。
        //又是用回溯法，这种类似的组合可以用这个回溯法。
        //先排序
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> combinate;
        combination(candidates, combinate, 0, target, res);
        return res;
    }

int main()
{
    vector<int> nums{1,8,4,5,7,2,3,10,30,2,4,15,12,15,17};
    //再写个二分查找，确定区间，减少无效递归。
    int left = 0, right = nums.size() - 1;
    while(left <= right)
    {
        int mid = (left + right) / 2;
        if(nums[mid] == 9)
            break;
        else if(nums[mid] > 9)
            right = mid - 1;
        else
            left = mid + 1;
    }
    cout << nums[left] << " " << nums[right] << endl;
    //二分这个left就是边界，传入0到left的数组。进行剪枝
    vector<vector<int>> ans = threeSum(nums, 9);
    for(int i = 0 ; i < ans.size();i++)
    {
        for(int j = 0 ; j < ans[i].size();j++)
            cout <<  ans[i][j] << " ";
        cout << endl;
    }
     vector<vector<int>> ans1 = combinationSum(nums, 9);
    for(int i = 0 ; i < ans1.size();i++)
    {
        for(int j = 0 ; j < ans1[i].size();j++)
            cout <<  ans1[i][j] << " ";
        cout << endl;
    }
    return 0;

}


    vector<vector<int>> threeSum(vector<int>& nums,int targetNum) {
        //阿里原题啊尼玛，但是改动了一下，这里的是加起来等于0，那么负数也是可以。原来的那个通用解法是不行了，会栈溢出不知道什么情况，估计是递归太多层了。这个题应该不是用这个方法， 应该需要弄一下这个
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i = 0;i < nums.size();i++)
            cout << nums[i] << " ";
        cout << endl;
        //固定两个数，然后找一个数是否相等为0。同时要判断数是否重复，如果重复直接跳过。
        
        //如果为空，或者最后一个值小于0、第一个值大于0。这种情况是没有解的。
        if (nums.empty() ) return {};
        for(int k = 0; k < nums.size();k++)
        {

            //相等则直接跳过，达到去重的效果
            if(k > 0 && nums[k] == nums[k - 1])
                continue;
            //用0减去fix的数得到一个target，然后再找到两个数之和等于target即可。
            int target = targetNum - nums[k];
            //类似二分，一个从头，一个从尾开始扫。如果和小于target，左边加1。如果和大于target，将右边减减，使和小一点，。
            int i = k + 1, j = nums.size() - 1;
            while(i < j)
            {
                if(nums[i] + nums[j] == target)
                {
                    // vector<int> now (3,0);
                    // now[0] = nums[k];
                    // now
                    ans.push_back(vector<int> {nums[k], nums[i], nums[j]});
                    // cout << nums[k] << " " << nums[i] << " " << nums[j] << endl;
                    while(i < j && nums[i] == nums[i + 1]) ++i;
                    while(i < j && nums[j] == nums[j - 1]) --j;
                    //去重完毕后还要左右移动一下
                    ++i;
                    --j;
                }
                else if (nums[i] + nums[j] < target) 
                    ++i;
                else
                    --j;
              
                //上面两个是去重效果
                
            }
        }
            return ans;
        
    }


vector<vector<int>> function1(vector<int>& nums, int target)
{
  vector<vector<int>> ans;
  sort(nums.begin(), nums.end());
  cout<< 1 <<endl;
  
  vector<int> combinate;
  helper(ans, combinate, nums,0 , target);
  return ans;
  
}

void helper(vector<vector<int>>& ans, vector<int>& combinate, vector<int>& candidates ,int start, int target)
{
  if(!target && candidates.size() == 3)
  { 
    cout << "test" << endl;
    ans.push_back(combinate);
    return;
  }
  for(int i = start; i < candidates.size() && target >= candidates[i]; i++)
  {
    cout << candidates[i] << endl;
    combinate.push_back(candidates[i]);
    
    helper(ans, combinate, candidates, i, target - candidates[i]);
    combinate.pop_back();
  }
}

