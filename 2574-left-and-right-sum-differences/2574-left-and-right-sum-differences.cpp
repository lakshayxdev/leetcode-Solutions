class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> prefix(nums.size());
        vector<int> sufix(nums.size());
        int sum=0;
        for(int i=0; i<nums.size(); i++) {
            sum+=nums[i];
            prefix[i]=sum;
        }
        sum=0;
        for(int i=nums.size()-1; i>=0; i--) {
            sum+=nums[i];
            sufix[i]=sum;
        }
        vector<int> ans(nums.size());
        int i=0;
        int j=0;
        while(i<prefix.size() && j<sufix.size()) {
            ans[i]=abs(prefix[i]-sufix[i]);
            i++;
            j++;
        }
        return ans;
    }
};