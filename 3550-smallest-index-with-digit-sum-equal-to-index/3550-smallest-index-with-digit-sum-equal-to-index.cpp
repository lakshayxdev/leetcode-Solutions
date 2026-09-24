class Solution {
public:
int digit_sum(int n) {
    int sum=0;
    int temp=n;
    while(temp>0) {
        int digit=temp%10;
        sum+=digit;
        temp=temp/10;
    }
    return sum;
}
    int smallestIndex(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++) {
            int sum=digit_sum(nums[i]);
            if(sum==i) {
                return i;
            }
        }
        return -1;
    }
};