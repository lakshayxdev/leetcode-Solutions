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
void inorder(TreeNode *root, vector<int> &ans) {
    if(root==NULL) {
        return ;
    }
    inorder(root->left, ans);
    ans.push_back(root->val);
    inorder(root->right, ans);
}
int i=0;
void final_inorder(TreeNode *root, vector<int> &ans) {
    if(root==NULL) {
        return ;
    }
    final_inorder(root->left,ans);
    if(root->val != ans[i]) {
         root->val=ans[i];
    }
    i++;
    final_inorder(root->right,ans);
}
    void recoverTree(TreeNode* root) {
        vector<int> ans;
        inorder(root,ans);
        sort(ans.begin(),ans.end());
        final_inorder(root,ans);
    }
};