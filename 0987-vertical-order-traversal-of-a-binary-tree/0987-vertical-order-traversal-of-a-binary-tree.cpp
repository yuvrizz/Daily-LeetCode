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

    map<int,vector<pair<int,int>>> mp;

    void inorder(TreeNode* root, int row, int col){

        if(root == NULL){
            return;
        }

        mp[col].push_back({row,root->val}); 

        inorder(root->left, row+1, col-1);
        inorder(root->right, row+1, col+1);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        inorder(root,0,0);
        vector<vector<int>> ans;

        for(auto& [col, nodes] : mp){

            sort(nodes.begin(),nodes.end());

            vector<int> temp;

            for (auto& [row, val] : nodes) {
                temp.push_back(val);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};