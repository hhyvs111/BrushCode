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

class Solution {
public:
    void flatten(TreeNode *root) {
        TreeNode *cur = root;
        while (cur) {
            //有左子树，说明该点还没被flat
            if (cur->left) {
                //遭到左子树的最右一个节点
                TreeNode *p = cur->left;
                while (p->right) p = p->right;
                //该节点的右子树指向cur的右子树
                p->right = cur->right;
                //然后cur的右子树指向自己的左子树，断开。
                cur->right = cur->left;
                cur->left = NULL;
            }
            cur = cur->right;
        }
    }
};

// 这道题要求把二叉树展开成链表，根据展开后形成的链表的顺序分析出是使用先序遍历，那么只要是数的遍历就有递归和非递归的两种方法来求解，这里我们也用两种方法来求解。首先来看递归版本的，思路是先利用DFS的思路找到最左子节点，然后回到其父节点，把其父节点和右子节点断开，将原左子结点连上父节点的右子节点上，然后再把原右子节点连到新右子节点的右子节点上，然后再回到上一父节点做相同操作。代码如下：
class Solution {
public:
    void flatten(TreeNode *root) {
        if (!root) return;
        //dfs找到最左节点
        if (root->left) flatten(root->left);
        if (root->right) flatten(root->right);
        //此时的root是最左节点的父节点，将root的right断开，把root的left接到right上。
        TreeNode *tmp = root->right;
        root->right = root->left;
        root->left = NULL;
        //然后再将tmp接到root->的最右节点，也就是将之前的left接到root->right->right上，背下来必须的！
        while (root->right) root = root->right;
        root->right = tmp;
    }
};