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
    void deleteNode(ListNode* node) {
        //这尼玛参数就一个啊，我寻思也没给啊。那么就给你一个node，我把这个node给删了。这个也是单链表吧
        //把node的值等于它下一个，这样就切断了？
   
        node->val = node->next->val;
        node->next = node->next->next;
        //这个题半天没看懂，输入明显有问题啊。
    }
};