class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ilen=1;
        int dlen=1;
        int imaxi=INT_MIN;
        int dmaxi=INT_MIN;
        int l=0;
        for(int r=0; r<nums.size()-1; r++) {
            if(nums[r]<nums[r+1]) {
                dmaxi=max(dmaxi,dlen);
                ilen++;
                dlen=1;
            }
            else if(nums[r]>nums[r+1]) {
                imaxi=max(imaxi,ilen);
                dlen++;
                ilen=1;
            }
            else {
                imaxi = max(imaxi, ilen);
                dmaxi = max(dmaxi, dlen);
                ilen = 1;
                dlen = 1;
}
        }
        dmaxi=max(dmaxi,dlen);
        imaxi=max(imaxi,ilen);
        return max(imaxi,dmaxi);
    }
};