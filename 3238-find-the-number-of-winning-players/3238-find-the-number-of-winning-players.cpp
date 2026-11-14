class Solution {
public:
bool solve(int val, vector<int> &nums) {
    if(nums.size()==1) {
        if(1>val) return true;
    }
    int ans=1;
    for(int i=0; i<nums.size()-1; i++) {
        if(nums[i]==nums[i+1]) {
            ans++;
        }
        else {
            if(ans>val) {
                return true;
            }
            else {
                ans=1;
            }
        }
    }
    if(ans>val) return true;
    return false;
}
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        int ans=0;
        unordered_map<int,vector<int>> mp;
        for(int i=0; i<pick.size(); i++) {
            int u=pick[i][0];
            int v=pick[i][1];
            mp[u].push_back(v);
        }
        for(auto it:mp) {
            vector<int> nums=it.second;
            int val=it.first;
            sort(nums.begin(),nums.end());
            bool flag=solve(val,nums);
            if(flag) ans++;
        }
        return ans;
    }
};