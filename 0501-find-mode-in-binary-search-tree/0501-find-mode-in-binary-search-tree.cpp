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
void traversal(TreeNode *root, vector<int> &dummy) {
    if(root==NULL) {
        return;
    }
    traversal(root->left,dummy);
    dummy.push_back(root->val);
    traversal(root->right,dummy);
}
    vector<int> findMode(TreeNode* root) {
        vector<int> nodes;
        traversal(root,nodes);
        unordered_map<int,int> mp;
        for(int i=0; i<nodes.size(); i++) {
            mp[nodes[i]]++;
        }
        vector<int> ans;

int maxFreq = 0;

for(auto it : mp) {
    maxFreq = max(maxFreq, it.second);
}

for(auto it : mp) {
    if(it.second == maxFreq) {
        ans.push_back(it.first);
    }
}

return ans;
    }
};