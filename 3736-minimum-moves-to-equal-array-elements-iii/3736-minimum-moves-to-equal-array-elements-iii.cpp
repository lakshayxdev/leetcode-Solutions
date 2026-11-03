class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxi=INT_MIN;
        for(int num:nums) {
            maxi=max(maxi,num);
        }
        int moves=0;
        for(int i=0; i<nums.size(); i++) {
            moves+=maxi-nums[i];
        }
         return moves;
    }
};