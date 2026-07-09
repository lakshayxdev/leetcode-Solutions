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
 bool ismirror(TreeNode *left, TreeNode *right) {
            if(left == NULL && right == NULL) {
                return true;
            }
             if(left != NULL && right == NULL) {
                return false;
            }
             if(left == NULL && right != NULL) {
                return false;
            }
             if(left->val != right->val) {
                return false;
            }
             bool ans1=ismirror(left->left, right->right);
       bool ans2=ismirror(left->right, right->left);
       return ans1 && ans2;
        }
        
    bool isSymmetric(TreeNode* root) {
      if(root==NULL) {
        return true;
      }
      return ismirror(root->left, root->right);
    }
};