/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /** @param head The linked list's head. Note that the head is guanranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        p = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        ListNode *tem = p;
        int val = p->val;
        for(int i =1; tem; i++)
        {
            //这里为什么是这个rand()i，因为每增加一个数，都有1/i的概率选择这个数，
            if(rand()%i==0) val = tem->val;
            tem = tem->next;
        }
        return val;
    }
private:
    ListNode *p;
};
/*
 蓄水池算法，一边加数，一边计算概率。
 假设当前有10个数，然后又新进来1个数，为11个数。当前的目标值肯定是10个数中的一个，概率为1。
 那么目标值替换为新进来的这个数（第11个数）的概率是10/11，其实也能当做是1/2（因为要确保概率相等）。
 然后如果我们不把目标值替换为新来的数的概率是多少呢？（比如我们要留下10里面的1）
 公式为 = 不选新值的概率 + （选新值的概率* 选除了1的其他值的概率）
 代入后可得：不替换的概率为 = 1/11 * (10/11 * 9/10) = 10/11
 
 然后依次递推数学归纳法。
 这里的1就是上面的10！
 
/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
