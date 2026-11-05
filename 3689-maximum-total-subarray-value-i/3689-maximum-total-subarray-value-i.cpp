class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int maxi=INT_MIN;
        int mini=INT_MAX;
        for(int num:nums) {
            maxi=max(maxi,num);
            mini=min(mini,num);
        }
        return (long long)(maxi-mini)*k;
    }
};