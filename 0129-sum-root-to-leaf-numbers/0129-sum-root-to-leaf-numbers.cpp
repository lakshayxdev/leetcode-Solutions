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
string str="";
void traverse(TreeNode *root, int &sum) {
    if(root==NULL) {
        return;
    }
    str+=to_string(root->val);
    if(root->left==NULL && root->right==NULL) {
        sum+=stoi(str);
    }
    traverse(root->left,sum);
    traverse(root->right,sum);
    str.pop_back();

}
    int sumNumbers(TreeNode* root) {
        if(root==NULL) {
            return 0;
        }
        int sum=0;
        traverse(root,sum);
        return sum;
        
    }
};