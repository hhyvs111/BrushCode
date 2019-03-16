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
    // vector<int> nums;
    bool isValidBST(TreeNode* root) {
        return valid(root, LONG_MIN, LONG_MAX);
    }
    bool valid(TreeNode* root, long min, long max)
    {
        if(!root) return true;
        if(root->val >= max || root->val <= min) return false;
        //主要是检查父节点的父节点是否满足。
        return valid(root->left, min, root->val) && valid(root->right, root->val, max);
    }
            
};
        
        
    //     if(!root) return true;
    //     inorder(root);
    //     //这样做太浪费空间了。也可以用栈做
    //     for(int i = 0 ; i < nums.size() - 1;i++)
    //     {
    //         if(nums[i] >= nums[i+1])
    //             return false;
    //     }
    //     return true;
    // }
    // //用一个vector，中序遍历，然后判断大小。
    // void inorder(TreeNode* root)
    // {
    //     if(root == NULL)return;
    //     if(root->left) inorder(root->left);
    //     nums.push_back(root->val);
    //     if(root->right) inorder(root->right);
    // }
    
