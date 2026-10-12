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
    int widthOfBinaryTree(TreeNode* root) {
        
        if(root == NULL){
            return 0;
        }

        queue <pair<TreeNode*,long long>> q; 
        q.push({root,0});

        long long maxWid = 0;

        while(q.size() > 0){

            long long start = q.front().second;
            long long end = q.back().second;
            maxWid = max(maxWid, end - start + 1);

            int currlvl = q.size();

            for(int i=0; i<currlvl; i++){
                pair <TreeNode*,int> currNode = q.front(); 
                q.pop(); 

                TreeNode* node = currNode.first;
                long long idx = currNode.second;

                if(node -> left){
                    q.push({node->left, 2*idx + 1});
                }
                if(node -> right){
                    q.push({node->right, 2*idx + 2});
                }
            }
        }

        return maxWid; 
    }
};