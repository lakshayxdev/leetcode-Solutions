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
bool check(vector<int> &ans, int i) {
    if(i>=ans.size()-1) {
        return true;
    }
    if(ans[i]>=ans[i+1]) {
        return false;
    }
    return check(ans,i+1);
}
void inorder(TreeNode *root, vector<int> &ans) {
    if(root==NULL) {
        return ;
    }
    inorder(root->left,ans);
    ans.push_back(root->val);
    inorder(root->right,ans);
}
    bool isValidBST(TreeNode* root) {
        if(root==NULL) {
            return true;
        }
        vector<int> ans;
        inorder(root,ans);
        return check(ans,0);
    }
};