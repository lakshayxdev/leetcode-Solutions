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
int findmax(int start, int end, vector<int> &nums) {
    int maxi=INT_MIN;
    int index=-1;
    for(int i=start; i<=end; i++) {
        maxi=max(maxi,nums[i]);
    }
    return maxi;
}
TreeNode *solve(vector<int> &nums, int start, int end, unordered_map<int,int> &mp) {
    if(start>end) {
        return NULL;
    }
    int max=findmax(start,end,nums);
    int index=mp[max];
    TreeNode *root=new TreeNode(max);
    root->left=solve(nums,start,index-1,mp);
    root->right=solve(nums,index+1,end,mp);
    return root;
}
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i=0; i<nums.size(); i++) {
            mp[nums[i]]=i;
        }
        return solve(nums,0,nums.size()-1,mp);
    }
};