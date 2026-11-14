class Solution {
public:
int findSum(vector<int> &nums, int size) {
    int s=0; 
    int mini=INT_MAX;
    int e=size-1;
    int sum=0;
    for(int i=s; i<=e; i++) {
        sum+=nums[i];
    }
    if(sum>0) mini=min(mini,sum);
    for(int i=e+1; i<nums.size(); i++) {
        sum+=nums[i];
        sum-=nums[s];
        s++;
        if(sum>0) mini=min(sum,mini);
    }
    return mini;
}
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int mini=INT_MAX;
        for(int i=l; i<=r; i++) {
            int sum=0;
            sum=sum+findSum(nums,i);
            if(sum>0) mini=min(mini,sum);
        }
        if(mini==INT_MAX) return -1;
        return mini;
    }
};