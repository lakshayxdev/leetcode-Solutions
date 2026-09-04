class Solution {
public:
int find_maxi(vector<int> &nums, int start, int end) {
    int maxi=INT_MIN;
    for(int i=start; i<=end; i++) {
        maxi=max(maxi,nums[i]);
    }
    return maxi;
}
int find_mini(vector<int> &nums, int start) {
    int mini=INT_MAX;
    for(int i=start; i<nums.size(); i++) {
        mini=min(mini,nums[i]);
    }
    return mini;
}
    int firstStableIndex(vector<int>& nums, int k) {
        for(int i=0; i<nums.size(); i++) {
            int max_value=find_maxi(nums,0,i);
            int min_value=find_mini(nums,i);
            if(max_value-min_value <= k) {
                return i;
            }
        }
        return -1;
    }
};