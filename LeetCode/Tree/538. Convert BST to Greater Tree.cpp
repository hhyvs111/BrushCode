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
    int sum = 0;
    TreeNode* convertBST(TreeNode* root) {
        //这个题什么意思，把二叉搜索树变为更大的树，就是当前值加上其他所有比这个值大的值。
        //5 只有13比他大，那么就加13，2的话5和13都比它大。
        //将树的从右至左递归，一个值加上一个值
       //直接递归自己，有点牛批，还用了sum，感觉我就是个傻逼。怎么这么蠢呢？
        if(root != NULL)
        {
            convertBST(root->right);
            sum += root->val;
            root->val = sum;
            convertBST(root->left);
        }
        return root;
        // if(root == NULL)
        //     return NULL;
        // TreeNode* ans = root;
        // //root的pre是它的右孩子
        // mid(root,NULL);
        // return ans;
    }
//     //用递归好像不行，之前存入的值是不对的。
//     //原则就是要加上所有的在其右边的值
//     void mid(TreeNode* root,TreeNode* pre)
//     {
//         if(root == NULL)
//             return;
//         //左子树的话，root加，右子树pre加
//         if(root->right != NULL)
//         {
//             mid(root->right, root);
            
//         }
//         if(pre != NULL)
//         {
//             // cout << root->val << " " << pre->val << endl;
//             // if(pre->val < root->val)
//             //     pre->val += root->val;
//             // else
//                 root->val += pre->val;
//         }
//         if(root->left != NULL)
//         {
//             mid(root->left,root);
            
//         }
//     }
};