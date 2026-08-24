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
unordered_map<int,int> locate;
TreeNode *build(vector<int>& preorder, vector<int>& postorder, int i1, int j1, int size) {
    if(size==0) {
        return NULL;
    }
    TreeNode *root=new TreeNode(preorder[i1]);
     if(size == 1) {
            return root;
        }
    int pos=locate[preorder[i1+1]];
    int leftsize=pos-j1+1;
    root->left=build(preorder,postorder, i1+1, j1, leftsize);
    root->right=build(preorder,postorder,i1+leftsize+1, j1+leftsize, size-1-leftsize);
    return root;
}
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        for(int i=0; i<postorder.size(); i++) {
            locate[postorder[i]]=i;
        }
        return build(preorder,postorder,0,0,preorder.size());
    }
};