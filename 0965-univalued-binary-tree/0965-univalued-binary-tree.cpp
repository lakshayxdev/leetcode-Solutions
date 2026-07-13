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
TreeNode *curr;
    bool isUnivalTree(TreeNode* root) {
        if(curr==NULL) {
            curr=root;
        }
        if(root==NULL) {
            return true;
        }
        bool left=isUnivalTree(root->left);
        bool right=isUnivalTree(root->right);
        if(root->val!=curr->val) {
            return false;
        }
        return left && right;
    }
};