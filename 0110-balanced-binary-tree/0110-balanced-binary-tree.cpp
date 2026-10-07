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

    int helper(TreeNode* root, int &valid){

        if(root == NULL){
            return 0;
        }

        int left = 1 + helper(root->left,valid);
        int right = 1 + helper(root->right,valid);

        if(abs(left-right) > 1){
            valid = 0;
        }

        return max(left,right);
    }

    bool isBalanced(TreeNode* root) {
        
        int valid = 1; 
        helper(root,valid);

        return valid;
    }
};