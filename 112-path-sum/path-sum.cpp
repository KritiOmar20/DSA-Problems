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
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool ans=false;
        if(root==NULL){
            return  false;
        }
        int sm=targetSum-root->val;
        if(sm==0 && root->left==NULL && root->right==NULL){
            return true;
        }
        if(root->left!=NULL){
            ans=ans || hasPathSum(root->left,sm);
        }
        if(root->right!=NULL){
            ans=ans || hasPathSum(root->right,sm);
        }
        return ans;
        
    }
};