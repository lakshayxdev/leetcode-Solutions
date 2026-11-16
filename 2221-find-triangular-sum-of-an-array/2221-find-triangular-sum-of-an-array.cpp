class Solution {
public:
    int triangularSum(vector<int>& nums) {
        while(nums.size()>1) {
            int j=0;
            for(int i=0; i<nums.size()-1; i++) {
                int sum=(nums[i]+nums[i+1])%10;;
                nums[j++]=sum;
            }
            nums.resize(j);
        }
        return nums[0];
    }
};