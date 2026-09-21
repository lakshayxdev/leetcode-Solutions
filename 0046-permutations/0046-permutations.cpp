class Solution {
public:
void solve(vector<int> &nums, vector<int> &ans, vector<vector<int>> &final_ans, unordered_map<int,bool> &visited,int start) {
    if(ans.size()==nums.size()) {
        final_ans.push_back(ans);
        return;
    }
    for(int i=0; i<nums.size(); i++) {
        if(!visited[nums[i]]) {
            ans.push_back(nums[i]);
            visited[nums[i]]=true;
            solve(nums,ans,final_ans,visited,i);
            ans.pop_back();
            visited[nums[i]]=false;
        }
    }
}
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int,bool> visited;
        vector<vector<int>> final_ans;
        int n=nums.size();
        solve(nums,ans,final_ans,visited,0);
        return final_ans;
    }
};