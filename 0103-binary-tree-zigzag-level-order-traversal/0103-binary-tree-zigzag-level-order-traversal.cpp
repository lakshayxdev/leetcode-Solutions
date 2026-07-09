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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> level;
        queue<TreeNode *> q;
        int count=0;
        q.push(root);
        q.push(NULL);
        if(root==NULL) {
            return {};
        }
        while(!q.empty()) {
            TreeNode *temp=q.front();
            q.pop();
            if(temp==NULL) {    // if front is null
            if(count % 2 == 1) {  // if level is odd
            reverse(level.begin(),level.end());
            ans.push_back(level);
            count=count+1;
            level.clear();
            if(!q.empty()) {    // pushing null if not empty
                q.push(NULL);
            }
            }
            else {          // if level is even
            ans.push_back(level);
            level.clear();
            count=count+1;
            if(!q.empty()) {        // pushing null if not empty
                q.push(NULL);
            }
            }
            }
            else {             // if front is not null
            level.push_back(temp->val);
            if(temp->left) {               // push left is exist
                q.push(temp->left);
            }
             if(temp->right) {         // push right if exist
                q.push(temp->right);
            }
            }
        }
        return ans;
    }
};