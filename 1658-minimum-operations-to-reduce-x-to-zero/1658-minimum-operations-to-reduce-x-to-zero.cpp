class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int maxi=INT_MIN;
        int totalsum=0;
        for(int i=0; i<nums.size(); i++) {
            totalsum+=nums[i];
        }
        int finalsum=totalsum-x;
        if(finalsum==0) {
            return nums.size();
        }
        if(finalsum<0) {
            return -1;
        }
        int l=0;
        int running=0;
        for(int r=0; r<nums.size(); r++) {
            running+=nums[r];
            while(running>finalsum) {
                running-=nums[l];
                l++;
            }
            if(running==finalsum) {
                maxi=max(maxi,r-l+1);
            }
        }
        if(maxi==INT_MIN) {
            return -1;
        }
        return nums.size()-maxi;
    }
};