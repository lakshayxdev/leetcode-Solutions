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
map<int,int> mp;
TreeNode *solve(vector<int>& postorder, int &postindex, int inorderstart, int inorderend) {
    if(postindex < 0 || inorderstart > inorderend) {
        return NULL;
    }
    int element=postorder[postindex--];
    TreeNode *node=new TreeNode(element);
    int position=mp[element];
    TreeNode *right=solve(postorder, postindex, position+1, inorderend);
    TreeNode *left=solve(postorder,postindex,inorderstart,position-1);
    node->right=right;
    node->left=left;
    return node;
}
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i=0; i<inorder.size(); i++) {
            mp[inorder[i]]=i;
        }
        int postindex=postorder.size()-1;
        return solve(postorder,postindex,0,inorder.size()-1);
    }
};