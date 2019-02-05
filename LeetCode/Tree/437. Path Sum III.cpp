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
    int pathSum(TreeNode* root, int sum) {
        if(root == NULL)
            return 0;
        //这里也递归调用，每次都传入根，并将其孩子传入
        return dfs(root, 0, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
        
    }
    int dfs(TreeNode* root,int pre, int &sum)
    {
        
        if(root == NULL)
            return 0;
        //当前值等于前一个值加上子树的值
        int cur = pre + root->val;
        //返回值等于当前个数，如果等于sum则技术+1
        return (cur == sum) + dfs(root->left, cur, sum) + dfs(root->right, cur, sum);
    }
    
    // void mid(TreeNode* root)
    // {
    //     if(root == NULL)
    //         return;
    //     if(root->left != NULL)
    //         mid(root->left);
    //     seq.push_back(root->val);
    //     cout << root->val << " ";
    //     if(root->right != NULL)
    //         mid(root->right);
    // }
};