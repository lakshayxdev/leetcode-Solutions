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
int preindex=0;
TreeNode *solve(vector<int>& preorder, vector<int>& inorder, int inorderstart, int inorderend) {
    if(preindex >= preorder.size() || inorderstart > inorderend) {
        return NULL;
    }
    int element=preorder[preindex++];
    TreeNode *node=new TreeNode(element);
    int position=mp[element];
    TreeNode *left=solve(preorder,inorder,inorderstart,position-1);
    TreeNode *right=solve(preorder,inorder,position+1,inorderend);
    node->left=left;
    node->right=right;
    return node;
}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0; i<inorder.size(); i++) {
            mp[inorder[i]]=i;
        }
        return solve(preorder,inorder,0,inorder.size()-1);
    }
};