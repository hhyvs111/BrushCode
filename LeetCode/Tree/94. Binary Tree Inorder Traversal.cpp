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
    vector<int> ans;
    vector<int> inorderTraversal(TreeNode* root) {
        // inorder(root);
        // return ans;
        
        stack<TreeNode*> s;
        TreeNode* node = root;
        while(node != NULL || !s.empty())
        {
            while(node != NULL)
            {
                s.push(node);
                node = node->left;
            }
            node = s.top();
            ans.push_back(node->val);
            s.pop();
            node = node->right;
        }
        return ans;
    }
    void inorder(TreeNode* root)
    {
        if(root == NULL)
            return;
        if(root->left != NULL)
            inorder(root->left);
        ans.push_back(root->val);
        if(root->right != NULL)
            inorder(root->right);
        
    }
};