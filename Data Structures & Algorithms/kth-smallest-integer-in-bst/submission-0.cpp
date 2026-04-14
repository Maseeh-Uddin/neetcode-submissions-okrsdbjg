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
    int ans;
    int curr=1;
public:
    int kthSmallest(TreeNode* root, int k) {
        
        inorder(root,k);
        return ans;
    }
private:
    void inorder(TreeNode* root, int k){
        if(root==NULL) return;

        inorder(root->left,k);
        if(curr==k){
            ans = root->val;
        }
        curr++;
        inorder(root->right,k);
        return;
    }
};
