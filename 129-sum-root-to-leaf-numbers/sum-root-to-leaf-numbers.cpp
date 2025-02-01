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
    int solve(TreeNode* root,int totalsum){
        if(!root) return 0;
        totalsum=totalsum*10+root->val;
        if(!root->left && !root->right){
            return totalsum;
        }
        int leftsum=solve(root->left,totalsum);
        int rightsum=solve(root->right,totalsum);
        return leftsum+rightsum;
    }
    int sumNumbers(TreeNode* root) {
       return solve(root,0);
    }
};