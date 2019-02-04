/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    //递推，用栈。用队列也可以
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return true;
        //左右一个栈，同时进行递归
        //镜面原理，将一个树分为两颗子树，他们符合一个规律。左子树等于另一个树的右子树。
        stack<TreeNode*> s;
        s.push(root);
        s.push(root);
        while(!s.empty())
        {
            TreeNode* t1 = s.top();
            s.pop();
            TreeNode* t2 = s.top();
            s.pop();
            //如果都为空则继续，可能有空节点
            if(t1 == NULL && t2 == NULL) continue;
            if(t1 == NULL || t2 == NULL) return false;
            if(t1->val != t2->val) return false;
            s.push(t1->left);
            s.push(t2->right);
            s.push(t1->right);
            s.push(t2->left);
        }
        return true;
    }


    //递归方法，人还是太菜了
    bool isSymmetric(TreeNode* root) {
        return mirror(root,root);
    }
    bool mirror(TreeNode* t1, TreeNode* t2)
    {
        if(t1 == NULL && t2 == NULL) return true;
        if(t1 == NULL || t2 == NULL) return false;
        return (t1->val == t2->val) && mirror(t1->left,t2->right) && mirror(t1->right, t2->left);
    }
    
    // //想了一个方法，同时递推，走到如果能走到相同的值，那么才是一样
    // //中序遍历不行，那么遍历两次也不行。
    // void mid(TreeNode* root)
    // {
    //     if(root == NULL)
    //         return;
    //     if(root->left != NULL) mid(root->left);
    //     nums.push_back(root->val);
    //     if(root->right != NULL) mid(root->right);
    //     return ;
    // }
    //  void midTwo(TreeNode* root)
    // {
    //     if(root == NULL)
    //         return;
    //     if(root->right != NULL) mid(root->right);
    //     numsRev.push_back(root->val);
    //     if(root->left != NULL) mid(root->left);
    //     return ;
    // }
};