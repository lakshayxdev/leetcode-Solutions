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
bool path(TreeNode *root, TreeNode *given, vector<TreeNode *> &ans) {
    if(root==NULL) {
        return false;
    }
    ans.push_back(root);
    if(root==given) return true;
    bool left=path(root->left,given,ans);
    bool right=path(root->right,given,ans);
    if(left || right) return true;
    else {
        ans.pop_back();
        return false;
    }

}
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *ans;
        vector<TreeNode *> ans1;
        vector<TreeNode *>ans2;
        if(root==NULL) {
            return {};
        }
        path(root,p,ans1);
        path(root,q,ans2);
        int n=min(ans1.size(),ans2.size());
        for(int i=0; i<n; i++) {
            if(ans1[i]==ans2[i]) {
                ans=ans1[i];
            }
        }
        return ans;
    }
};