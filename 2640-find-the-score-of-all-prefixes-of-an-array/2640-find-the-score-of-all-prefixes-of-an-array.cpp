class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        vector<long long> ans(nums.size());
        long long score=0;
        int maxi=INT_MIN;
        for(int i=0; i<nums.size(); i++) {
            maxi=max(maxi,nums[i]);
            score+=nums[i]+maxi;
            ans[i]=score;
        }
        return ans;
    }
};