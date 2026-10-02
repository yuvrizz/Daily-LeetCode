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

    void helper(TreeNode* root, int depth, pair<int,int> &deepest){

        if(root == NULL){
            return;
        }

        if(depth > deepest.first){
            deepest.first = depth;
            deepest.second = root->val;
        }
        else if(depth == deepest.first){
            deepest.second += root->val;
        }

        helper(root->left,depth+1,deepest);
        helper(root->right,depth+1,deepest);
    }

    int deepestLeavesSum(TreeNode* root) {
        
        pair <int,int> deepest = {-1,0};

        helper(root,0,deepest);

        return deepest.second;
    }
};