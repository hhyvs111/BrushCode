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
    bool isPalindrome(ListNode* head) {
        
        //是否是回文链表，用O(N)实现，还要O(1)空间，那么就不能用数组了。
        ListNode* copyHead = head;
        int cnt = 0;
        while(copyHead != NULL)
        {
            cnt++;
            copyHead = copyHead->next;
        }
        //反转中间的链表，主要是处理单复数的情况，如果是单数则直接走一个？
        //sb了，直接反转，然后对比也行啊。我还写这么多！
        int mid = cnt/2;
        //反转链表的表头
        ListNode* reverseHead = NULL;
        // ListNode* reverseCopyHead = head;
        ListNode* tmp;
        
        while(mid--)
        {
            // tmp = reverseCopyHead;
            // reverseCopyHead = reverseCopyHead->next;
            // tmp->next = reverseCopyHead;
            tmp = head;
            head = head->next;
            tmp->next = reverseHead;
            reverseHead = tmp;
        }
        // while(reverseHead != NULL)
        // {
        //     cout << reverseHead->val ;
        //         reverseHead = reverseHead->next;
        // }
        // cout << endl;
        // while(head != NULL)
        // {
        //     cout << head->val ;
        //         head = head->next;
        // }
        mid = cnt/2;
        if(cnt%2)
        {
            head = head->next;
            
        }
        while(mid--)
        {
            cout << "data" << endl;
            cout << head->val << " " << reverseHead->val << endl;
            if(head->val != reverseHead->val)
                return false;
            head = head->next;
            reverseHead = reverseHead->next;
        }
        return true;
    }
    
};