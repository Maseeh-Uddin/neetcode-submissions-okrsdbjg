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
    bool isValidBST(TreeNode* root, int maxi=INT_MAX, int mini=INT_MIN) {
        
        if(root==NULL) return true;

        //int ans = true;
cout<<root->val<<mini<<maxi<<endl;
if(!(root->val>mini &&root->val <maxi)) return false;
        return (root->left ? root->val > root->left->val : true) && (root->right ? root->val < root->right->val : true) &&
        isValidBST(root->left,min(maxi,root->val),mini) && isValidBST(root->right,maxi,max(mini,root->val));

    }
};
