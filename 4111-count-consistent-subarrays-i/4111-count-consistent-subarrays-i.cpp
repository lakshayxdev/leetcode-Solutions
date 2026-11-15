class Solution {
public:
pair<int,int> solve(vector<int> &nums, int l, int r) {
    int mini=INT_MAX;
    for(int i=l; i<=r; i++) {
        mini=min(mini,nums[i]);
    }
    int ans=-1;
    for(int i=l; i<=r; i++) {
        ans=ans&nums[i];
    }
    return {mini,ans};
}
    int countConsistent(vector<int>& nums) {
        int count=0;
        for(int i=0; i<nums.size(); i++) {
            for(int j=i; j<nums.size(); j++) {
                pair<int,int> p=solve(nums,i,j);
                if(p.first==p.second) count++;
            }
        }
        return count;
    }
};