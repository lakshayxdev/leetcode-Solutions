class Solution {
public:
void solve(vector<int> &nums, vector<int> &ans, vector<vector<int>> &final_ans, int start) {
    
        final_ans.push_back(ans);
        
    for(int i=start; i<nums.size(); i++) {
        if(i>start && nums[i]==nums[i-1]) {
            continue;
        }
        ans.push_back(nums[i]);
        solve(nums,ans,final_ans,i+1);
        ans.pop_back();
    }
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> ans;
        vector<vector<int>> final_ans;
        solve(nums,ans,final_ans,0);
        return final_ans;
    }
};