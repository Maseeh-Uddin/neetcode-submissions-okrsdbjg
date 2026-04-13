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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        int a = min(p->val,q->val);
        int b = max(p->val,q->val);

        TreeNode* node = root;

        while(!(node->val >= a && node->val <= b)){
            if(node->val < a){
                node = node->right;
            }
            else{
                node = node->left;
            }
        }

        return node;
    }
};
