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
    bool hasCycle(ListNode *head) {
        //给一个pos，如果有连环则删除，又是快慢指针？
        if(!head)
            return false;
        ListNode* fast = head;
        ListNode* slow = head;
        while(1)
        {
            // cout << fast->val <<endl;
            if(fast->next == NULL || fast->next->next == NULL )
                return false;
            slow = slow->next;
            fast = fast->next->next;
            
            if(fast == slow)
                return true;
            
        }
        //只需要保证快指针不为空就行
        // while(fast -> next && fast -> next -> next){
        //     fast = fast -> next -> next;
        //     slow = slow -> next;
        //     if(fast == slow)
        //         return true;
        // }
        return false;
        
    }
};