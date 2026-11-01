class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        int mini=INT_MAX;
        for(int i=0; i<nums1.size(); i++) {
            for(int j=0; j<nums2.size(); j++) {
                if(nums1[i]==nums2[j]) {
                    mini=min(mini,nums1[i]);
                }
                else {
                    mini=min(mini,nums1[i]*10+nums2[j]);
                     mini=min(mini,nums2[j]*10+nums1[i]);
                }
            }
        }
        return mini;
    }
};