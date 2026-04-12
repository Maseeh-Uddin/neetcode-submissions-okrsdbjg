/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
    int maxi = 0;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int h = maxDepth(root);
        return maxi;
    }

    int maxDepth(TreeNode* root){
        if(root==NULL) return 0;

        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);

        maxi = max(maxi, leftDepth + rightDepth);
        return 1 + max(leftDepth, rightDepth);
    }
};
