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
    unordered_map<long long, int> mp;
    int count = 0;

    void dfs(TreeNode* root, long long currentSum, int targetSum) {
        if (root == NULL)
            return;
        currentSum += root->val;
        count += mp[currentSum - targetSum];
        mp[currentSum]++;
        dfs(root->left, currentSum, targetSum);
        dfs(root->right, currentSum, targetSum);
        mp[currentSum]--;
    }

    int pathSum(TreeNode* root, int targetSum) {
        mp[0] = 1;     
        dfs(root, 0, targetSum);
        return count;
    }
};