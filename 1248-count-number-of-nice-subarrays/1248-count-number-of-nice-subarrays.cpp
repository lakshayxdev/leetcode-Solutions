class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        for(int i=0; i<nums.size(); i++) {
            if(nums[i]%2==0) {
                nums[i]=0;
            }
            else {
                nums[i]=1;
            }
        }
        int l=0;
        int count=0;
        int sum=0;
        int zeroes=0;
        for(int r=0; r<nums.size(); r++) {
            sum+=nums[r];
             while(sum > k) {
                sum-=nums[l];
                l++;
                zeroes=0;
            }

            if(sum==k) {
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