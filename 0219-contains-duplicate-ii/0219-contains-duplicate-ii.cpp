class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,vector<int>> mp;
        for(int i=0; i<nums.size(); i++) {
            if(mp[nums[i]].empty()) {
                mp[nums[i]].push_back(i);
            }
            else {
                for(int x:mp[nums[i]]) {
                    if(abs(x-i) <= k) {
                        return true;
                    }
                }
                mp[nums[i]].push_back(i);
            }
        }
        return false;
    }
};