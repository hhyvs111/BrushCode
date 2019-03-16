class Solution {
public:
    vector<int> nums;
    bool isValidBST(TreeNode* root) {
        inorder(root);
        set<int> copy(nums.begin(), nums.end());
        vector<int> copy1 (copy.begin(), copy.end());
        if(copy1 != nums)
            return false;
        return true;
    }
    //用一个vector，中序遍历，然后判断大小。
    void inorder(TreeNode* root)
    {
        if(root == NULL)return;
        if(root->left) inorder(root->left);
        nums.push_back(root->val);
        if(root->right) inorder(root->right);
    }
};