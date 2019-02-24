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
    TreeNode* prev = NULL;
    void flatten(TreeNode* root) {
        if(!root) return;
        //就是面经上看到的，将链表转换成链表,注意这里是原地，就是改变这个root、
        //好像不是那么容易啊，尼玛哦
        //后序倒过来
        flatten(root->right);
        flatten(root->left);
        root->right = prev;
        root->left = NULL;
        prev = root;
    }
};


public class Solution {
    public void flatten(TreeNode root) {
        while(root != null){
            // 当存在左子树时，说明该节点还没被flat
            if(root.left != null){
                // 找到左子树最后一个节点
                TreeNode endOfLeftSubTree = root.left;
                while(endOfLeftSubTree.right != null){
                    endOfLeftSubTree = endOfLeftSubTree.right;
                }
                // 将右子树加到左子树最后一个节点的右边
                endOfLeftSubTree.right = root.right;
                // 将左子树放到当前节点的右边
                root.right = root.left;
                // 将当前节点左边置空
                root.left = null;
            }
            // 移动到下一个待flat的节点
            root = root.right;
        }
    }
}