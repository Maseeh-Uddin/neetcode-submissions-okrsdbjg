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
    int ans = 0;
public:
    int goodNodes(TreeNode* root) {
        heightTraverse(root);
        return ans;
        
    }
    void heightTraverse(TreeNode* root, int maxi=-101){
        if(root==NULL) return;
       if(root->val >= maxi){
        maxi = root->val;
        ans += 1;
       } 
        heightTraverse(root->left, maxi);
        heightTraverse(root->right, maxi);

        return;
    }
};
