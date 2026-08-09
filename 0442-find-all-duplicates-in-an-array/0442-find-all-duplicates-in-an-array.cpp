class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        if(nums.size()==1) {
            return {};
        }
        unordered_map<int,int> freq(0);
        for(int i=0; i<nums.size(); i++) {
            freq[nums[i]]++;
        }
        for(auto &it: freq) {
            if(it.second==2) {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};