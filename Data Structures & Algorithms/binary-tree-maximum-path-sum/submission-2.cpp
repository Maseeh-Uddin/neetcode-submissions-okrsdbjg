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
    int ans=INT_MIN;
public:
    int maxPathSum(TreeNode* root) {
        solve(root);
        return ans;
    }
    int solve(TreeNode* root){

        if(root==NULL) return INT_MIN;

        int left = solve(root->left);
        int right = solve(root->right);
        int val = root->val;
        ans = max(ans,(left>0?left:0)+(right>0?right:0)+val);
        int maxi=max(left,right);
        cout<<val<<left<<right<<maxi<<" "<<( maxi >= 0 ? maxi  : 0)<<endl;
        return val +( maxi >= 0 ? maxi  : 0);
    }
};
