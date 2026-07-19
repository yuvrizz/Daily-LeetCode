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

    int helper(TreeNode* root, int &count){
        
        if(root == NULL){
            return 0;
        }

        int left_max = helper(root->left,count);
        int right_max = helper(root->right,count);

        int max_el = max(root->val, max(left_max,right_max));

        if(root->val >= left_max && root->val >= right_max){
            count++;
        }

        return max_el;
    }
    
    
    int countDominantNodes(TreeNode* root) {

        int count = 0;
        helper(root,count);
        return count;
    }
};