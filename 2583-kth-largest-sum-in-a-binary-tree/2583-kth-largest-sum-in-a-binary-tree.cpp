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
long long findsum(vector<int> &dummy, long long sum) {
    for(int i=0; i<dummy.size(); i++) {
        sum+=dummy[i];
    }
    return sum;
}
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> store_sum;
        vector<vector<int>> ans;
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        vector<int> level;
        while(!q.empty()) {
            TreeNode *temp=q.front();
            q.pop();
            if(temp==NULL) {
                ans.push_back(level);
                level.clear();
                if(!q.empty()) {
                    q.push(NULL);
                }
            }
            else {
                level.push_back(temp->val);
                if(temp->left) {
                    q.push(temp->left);
                }
                if(temp->right) {
                    q.push(temp->right);
                }
            }
        }
        for(int i=0; i<ans.size(); i++) {
            long long sum=findsum(ans[i],0);
            store_sum.push_back(sum);
        }
         if(store_sum.size() < k) {
            return -1;
        }
        sort(store_sum.begin(),store_sum.end());
        return store_sum[store_sum.size()-k];
    }
};