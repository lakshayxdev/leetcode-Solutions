class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int l=0;
        long long maxi=0;
        long long sum=0;
        int unique=0;
        unordered_map<int,int> mp;
        for(int r=0; r<nums.size(); r++) {
            sum+=nums[r];
            if(mp[nums[r]]==0) {
                unique++;
            }
            mp[nums[r]]++;
            if(r-l+1==k) {
                if(k==unique) {
                    maxi=max(maxi,sum);
                }
                sum-=nums[l];
                mp[nums[l]]--;
                if(mp[nums[l]]==0) {
                    unique--;
                }
                l++;
            }
        }
        return maxi;
    }
};