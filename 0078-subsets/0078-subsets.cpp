class Solution {
public:
void solve(vector<int> &nums, vector<int> &ans, vector<vector<int>> &final_ans, int start) {
    if(start==nums.size()) {
        final_ans.push_back(ans);
        return;
    }
    ans.push_back(nums[start]);
    solve(nums,ans,final_ans,start+1);
    ans.pop_back();
    solve(nums,ans,final_ans,start+1);
}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> ans;
        vector<vector<int>> final_ans;
        solve(nums,ans,final_ans,0);
        return final_ans;
    }
};