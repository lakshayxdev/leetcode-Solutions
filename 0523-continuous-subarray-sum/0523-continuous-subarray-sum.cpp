class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(nums.size()==1) {
            return false;
        }
        unordered_map<int,int> mp;
        mp[0]=-1;
        int prefix=0;
        for(int i=0; i<nums.size(); i++) {
            prefix+=nums[i];
            int rem=(k==0)?prefix:prefix%k;
            if (mp.count(rem)) {
                if (i - mp[rem] >= 2) {
                    return true;
                }
            } else {
                mp[rem] = i;
            }
        }
        return false;
    }
};