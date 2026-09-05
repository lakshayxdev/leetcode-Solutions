class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
        unordered_map <int,bool> mp;
        for(int i=lower; i<=upper; i++) {
            mp[i]=false;
        }

        for(int i=0; i<nums.size(); i++) {
            mp[nums[i]]=true;
        }

        vector<int> missing;
        for(auto it:mp) {
            if(it.second==false) {
                missing.push_back(it.first);
            }
        }

        if(missing.empty())
    return {};

        vector<vector<int>> ranges;
        sort(missing.begin(),missing.end());
        int start = missing[0];

for(int i = 1; i < missing.size(); i++) {
    if(missing[i] != missing[i-1] + 1) {
        ranges.push_back({start, missing[i-1]});
        start = missing[i];
    }
}
ranges.push_back({start, missing.back()});

return ranges;        


    }
};