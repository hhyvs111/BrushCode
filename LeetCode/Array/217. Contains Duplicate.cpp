#include <set>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        return nums.size() > set<int>(nums.begin(), nums.end()).size();        
    }
    //这个题可以用set，也可以用hashmap，还可以排序，但是自己还是只会用暴力。
};