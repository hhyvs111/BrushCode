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
    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int> m;
        return dfs(root, m);
    }
    //如果左子树不为空，那么两种情况，一个是当前值加上其左右孙子的值。然后一种是不加当前的值，只加其左右子树的值。然后递归处理，这里用了map来保存之前的值。
    int dfs(TreeNode *root, unordered_map<TreeNode*, int> &m) {
        if (!root) return 0;
        if (m.count(root)) return m[root];
        int val = 0;
        if (root->left) {
            val += dfs(root->left->left, m) + dfs(root->left->right, m);
        }
        if (root->right) {
            val += dfs(root->right->left, m) + dfs(root->right->right, m);
        }
        //这里判断自己加孙子的值和儿子的值哪个大
        val = max(val + root->val, dfs(root->left, m) + dfs(root->right, m));
        m[root] = val;
        return val;
    }
};