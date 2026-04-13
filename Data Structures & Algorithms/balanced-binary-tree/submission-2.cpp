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
    bool ans=1;
public:
    bool isBalanced(TreeNode* root) {
        
        if(root == NULL) return true;

        treeLen(root);
        return ans;
    }

    int treeLen(TreeNode* root) {
        if(root==NULL) return 0;

        int left = treeLen(root->left);
        int right = treeLen(root->right);

        ans = ans && (abs(left-right) <= 1);

        return 1+max(left,right);
    }
};
