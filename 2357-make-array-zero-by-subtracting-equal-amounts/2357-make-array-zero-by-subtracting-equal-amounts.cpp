class Solution {
public:
int find_mini(vector<int> &arr) {
    int mini=INT_MAX;
    for(int i=0; i<arr.size(); i++) {
        if(arr[i]==0) {
            continue;
        }
        else {
            mini=min(mini,arr[i]);
        }
    }
    if(mini==INT_MAX) {
        return -1;
    }
    else {
        return mini;
    }
}
    int minimumOperations(vector<int>& nums) {
        if(find_mini(nums) == -1) {
            return 0;
        }
        int count=0;
        int value=find_mini(nums);
        while(value != -1) {
            for(int i=0; i<nums.size(); i++) {
            if(nums[i]!=0) {
                nums[i]=nums[i]-value;
            }
        }
        count++;
        value=find_mini(nums);
        }
        return count;   
    }
};