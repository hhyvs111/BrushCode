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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //二叉搜索树最近公共节点。
        //节点都在右子树的情况
        TreeNode* ans = root;
        if(p->val > root->val && q->val > root->val )
            ans = lowestCommonAncestor(root->right, p, q);
        //节点都在右子树的情况
        else if( p->val < root->val && q->val < root->val)
            ans = lowestCommonAncestor(root->left, p, q);
        //如果节点一个在左一个在右或者相等的情况，那么就是要
        return ans;
    }
};