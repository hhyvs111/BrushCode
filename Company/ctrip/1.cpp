#include <iostream>
#include <vector>
#include <numeric>
#include <limits>

using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int val){
        this->val=val;
        this->next=NULL;
    };
};

/*请完成下面这个函数，实现题目要求的功能
******************************开始写代码******************************/
ListNode* partition(ListNode* head,int m) {
		//定义两个链表
        ListNode* less = new ListNode(0);
        ListNode* more = new ListNode(0);
        ListNode* lessCur = less;
        ListNode* moreCur = more;
        ListNode* cur = head;
        //遍历节点
        while(cur)
        {
            if(cur->val >= m)
            {
                moreCur->next = cur;
                moreCur = cur;
                cur = cur->next;
                moreCur->next = NULL;
            }
            else
            {
                lessCur->next = cur;
                lessCur = cur;
                cur = cur->next;
                lessCur->next = NULL;
            }
        }
        lessCur->next = more->next;
        head = less->next;
        return head;
}
/******************************结束写代码******************************/


int main() {
    ListNode* head=NULL;
    ListNode* node=NULL;
    int m;
    cin>>m;
    int v;
    while(cin>>v){
        if(head==NULL){
            node=new ListNode(v);
            head=node;
        }else{
            node->next=new ListNode(v);
            node=node->next;
        }
    }
    head = partition(head,m);
    if(head!=NULL){
        cout<<head->val;
        node=head->next;
        delete head;
        head=node;
        while(head!=NULL){
            cout<<","<<head->val;
            node=head->next;
            delete head;
            head=node;
        }
    }
    cout<<endl;
    return 0;
}
