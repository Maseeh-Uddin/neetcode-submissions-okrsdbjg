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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        return traverse(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1);
    }
    TreeNode* traverse(vector<int>& preorder, vector<int>& inorder,int pl,int pr,int il, int ir){
if(pl>pr || il>ir) return NULL;
        TreeNode* root = new TreeNode();
        root->val = preorder[pl];

        int rootIndex = find(inorder.begin(),inorder.end(),root->val) - inorder.begin() ;
        root->left = traverse(preorder,inorder,pl+1,pl+rootIndex-il,il,rootIndex-1);
        root->right = traverse(preorder,inorder,pl+rootIndex+1-il,pr,rootIndex+1, ir);
        return root;
    }
};
