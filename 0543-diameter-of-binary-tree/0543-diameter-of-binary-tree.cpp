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



// APPROACH. 1  O(n^2)
// Root included + if Not included. 

// class Solution {
// public:

//     int height(TreeNode* root){
//         if(root == NULL){
//             return 0; 
//         }

//         int left = height(root->left);
//         int right = height(root->right);

//         int height = max(left,right)+1;

//         return height;
//     }

//     int diameterOfBinaryTree(TreeNode* root) {
        
//         if(root == NULL){
//             return 0; 
//         }

//         int currdiam = height(root->left) + height(root->right);
//         int leftdiam = diameterOfBinaryTree(root->left);
//         int rightdiam = diameterOfBinaryTree(root->right);

//         return max(currdiam, max(leftdiam,rightdiam));
//     }
// };



// APPROACH. 2  O(n)
// Diameter + Height calculated together

// class Solution {
// public:

//     pair<int,int> diameter_pair(TreeNode* root){
//         if(root == NULL){
//             return make_pair(0,0); 
//         }

//         // Diameter, Height
//         pair<int,int> leftInfo = diameter_pair(root->left);
//         pair<int,int> rightInfo = diameter_pair(root->right);

//         int currDiam = leftInfo.second + rightInfo.second;
//         int finalDiam = max(currDiam, max(leftInfo.first, rightInfo.first));
//         int finalHeight = max(leftInfo.second, rightInfo.second) + 1;

//         return make_pair(finalDiam,finalHeight);
//     }

//     int diameterOfBinaryTree(TreeNode* root) {
//         return diameter_pair(root).first;
//     }
// };


class Solution {
public:
    int ans = 0;

    int height(TreeNode* root){

        if(root == NULL){
            return 0;
        }

        int left = height(root->left);
        int right = height(root->right);

        ans = max(ans,left+right);

        return max(left,right) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        height(root);

        return ans;
    }
};