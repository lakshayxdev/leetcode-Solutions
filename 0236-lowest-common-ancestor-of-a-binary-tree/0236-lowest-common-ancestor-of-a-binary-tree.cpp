/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
bool path(TreeNode *root, vector<TreeNode *> &ans, TreeNode *n) {
    if(root==NULL) {
        return false;
    }
    ans.push_back(root);
    if(root==n) {
        return true;
    }
    if(path(root->left, ans,n) || path(root->right, ans, n)) {
        return true;
    }
    ans.pop_back();
    return false;
}
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *final_ans;
        if(root==NULL) {
            return NULL;
        }
        vector<TreeNode *> ans1;
        vector<TreeNode *> ans2;
        path(root,ans1,p);
        path(root, ans2,q);
       int n=min(ans1.size(),ans2.size());
       for (int i=0; i<n; i++) {
        if(ans1[i]==ans2[i]) {
            final_ans=ans1[i];
        }
        else {
            break;
        }
       }
        return final_ans;
    }
};