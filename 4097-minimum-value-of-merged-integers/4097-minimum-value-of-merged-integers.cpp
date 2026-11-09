class Solution {
public:
    int minMergedInteger(vector<int>& nums) {
        int mini=INT_MAX;
        int i=0;
        while(i<nums.size()) {
            string ans=to_string(nums[i])+to_string(nums[i+1]);
            int val=stoi(ans);
            mini=min(val,mini);
            i+=2;
        }
        return mini;
    }
};