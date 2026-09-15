class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        if(goal==0) {
            int count=0;
            int zeroes=0;
            for(int num:nums) {
                if(num==0) {
                    zeroes++;
                    count+=zeroes;
                }
                else {
                    zeroes=0;
                }
            }
            return count;
        }
        int l=0;
        int count=0;
        int zeroes=0;
        int sum=0;
        for(int r=0; r<nums.size(); r++) {
            sum+=nums[r];
            while(sum > goal) {
                sum-=nums[l];
                l++;
                zeroes=0;
            }
             if(sum==goal) {
                while(l<=r && nums[l]==0) {
                    zeroes++;
                    l++;
                }
                count+=zeroes+1;
             }
        }
        return count;
    }
};