class Solution {
public:
int findUnique(int start, int end, vector<int> &nums) {
    unordered_map<int,int> mp;
    for(int i=start; i<=end; i++) {
        mp[nums[i]]++;
    }
    return mp.size();
}
    int sumCounts(vector<int>& nums) {
        int ans=0;
        for(int i=0; i<nums.size(); i++) {
            for(int j=i; j<nums.size(); j++) {
                int unique=findUnique(i,j,nums);
                ans+=(unique*unique);
            }
        }
        return ans;
    }
};