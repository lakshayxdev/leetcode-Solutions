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
int mini=INT_MAX;
void traverse(TreeNode *root, vector<int> &order) {
    if(root==NULL) {
        return;
    }
    traverse(root->left,order);
    order.push_back(root->val);
    traverse(root->right,order);
}
    int getMinimumDifference(TreeNode* root) {
        vector<int> order;
        traverse(root,order);
        for(int i=0; i<order.size()-1; i++) {
            mini=min(mini,abs(order[i]-order[i+1]));
        }
        return mini;
    }
};