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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //从尾节点删除两个节点
        //二分法找节点 ，找你妈！
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* first = dummy;
        ListNode* second = dummy;
        //先first走n个位置,这里+1是因为定义了一个头结点
        for(int i = 0 ; i < n + 1;i++)
        {
            cout << first->val << endl;
            first = first->next;
        }
        //然后second和first同时走，当first走到最后一个节点的时候，second就走到了倒数第n个位置，基于对称性
        while(first)
        {
            first = first->next;
            second = second->next;
        }
        //删除second这个节点
        second->next = second->next->next;
        return dummy->next;
        
    }
    
    // void binarySearch(ListNode * head, int n)
    // {
    //     ListNode* dummy = new ListNode(-1);
    //     dummy->next = head;
    //     ListNode* fast = dummy;
    //     ListNode* slow = dummy;
    //     ListNode* pre = dummy;
    //     int cnt = 0;
    //     while(fast && fast->next)
    //     {
    //         pre = slow;
    //         slow = slow->next;
    //         cnt++;
    //         fast = fast->next->next;
    //     }
    //     cout << cnt << " " << n << endl;
    //     if(cnt > n)  
    //     {
    //         binarySearch(slow, n);
    //     }
        //找到了，
//         else if(cnt == n)
//         {
//             cout <<" test "<< cnt << " "<< n <<endl;
//             cout<< slow->val <<endl;
//             cout << pre->val << endl;
//              if(slow->next != NULL)
//                  pre->next = pre->next->next;
//              else
//                  slow = NULL;
//             //slow的下一个节点就是要删除的节点
// //             if(slow->next != NULL)
// //             {
                
// //                 slow = slow->next;
// //                 cout << " delete"<<endl;
// //             }
//             // else
//             // {
//             //     cout << "dede111" << slow->val << endl;
//             //     slow = NULL;
//             // }
                
//         }
//         //这里处理大于cnt的情况，直接置为null,然后n-cnt
//         else
//         {
//             binarySearch(head, n - cnt - 1);
//         }
};