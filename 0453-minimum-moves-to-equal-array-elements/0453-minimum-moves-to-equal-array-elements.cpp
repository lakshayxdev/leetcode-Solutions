class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mini=INT_MAX;
        for(int num:nums) {
            mini=min(mini,num);
        }
        int count=0;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i]==mini) continue;
            else {
                count+=nums[i]-mini;
            }
        }
        return count;
    }
};