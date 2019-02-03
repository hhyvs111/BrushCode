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
    int maxDepth(TreeNode* root) {
        //用dfs
        if(root == NULL)
            return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};

//还是太菜，要了解一下这个二叉树的性质在做吧，吗的这个dfs和递归真的是难哦。