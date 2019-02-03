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
    int diameterOfBinaryTree(TreeNode* root) {
        //这个直径还不是走根节点，可以走子节点
        //算直径，左子树的长度加右子树,其实就是两个子树求最大深度
        if(root == NULL)
            return 0;
        //如果最大长度过了根节点，那么长度就是左右子树的高度
        int res = maxDepth(root->left) + maxDepth(root->right);
        //如果不是在根节点，那么判断res和以子节点作为根的res哪个大
        return max(res, max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right)));
    }
    int maxDepth(TreeNode* root) {
        //用dfs
        if(root == NULL)
            return 0;
        return  1 + max(maxDepth(root->left), maxDepth(root->right));
    }
    //方法二，只递归调用一次。
    int ans;
    int diameterOfBinaryTree(TreeNode* root) {
        //这个直径还不是走根节点，可以走子节点
        //算直径，左子树的长度加右子树,其实就是两个子树求最大深度
        if(root == NULL)
            return 0;
        maxDepth(root);
        return ans;
    }
    int maxDepth(TreeNode* root) {
        //用dfs
        if(root == NULL)
            return 0;
        int right = maxDepth(root->right);
        int left = maxDepth(root->left);
        ans = ans > (left + right) ? ans : (left + right);
        //这里的返回值就是return  1 + max(maxDepth(root->left), maxDepth(root->right));子树的深度
        return left > right ?  left + 1 : right + 1;
    }
    //上面那个方法不是很好，有点浪费空间了。
    
};