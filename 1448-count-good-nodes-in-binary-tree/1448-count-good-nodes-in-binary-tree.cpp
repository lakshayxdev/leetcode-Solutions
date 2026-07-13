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
int count=0;
void traversal(TreeNode *root, int maxsofar) {
    if(root==NULL) {
        return;
    }
    if(root->val >= maxsofar) {
        count++;
        maxsofar=max(root->val,maxsofar);
    }
    traversal(root->left, maxsofar);
    traversal(root->right, maxsofar);
}
    int goodNodes(TreeNode* root) {
        traversal(root,root->val);
        return count;
    }
};