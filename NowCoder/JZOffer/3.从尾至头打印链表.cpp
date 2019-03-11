/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> arrayList;
        //ListNode *p = head;
        while(head!=NULL)
        {
            arrayList.push_back(head->val);
            head = head->next;
        }
        //链表倒置啊这个题，空间换时间。
        int size = arrayList.size();
        for(int i = size - 1; i >= (size / 2); i--)
        {
            //这里要用交换
            int temp = arrayList[size - i - 1];
            arrayList[size - i - 1] = arrayList[i];
            arrayList[i] = temp;
        }
        return arrayList;
    }
};