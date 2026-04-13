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
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
         if(root==NULL) return 0;

        if(root->val==subRoot->val) return isEquiv(root,subRoot) || isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
        else {
            return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
        }
    }
    bool isEquiv(TreeNode* a, TreeNode* b){
        if(a==NULL || b==NULL) return a==NULL && b==NULL;

        return a->val==b->val && isEquiv(a->left,b->left) && isEquiv(a->right,b->right);
    }
};
