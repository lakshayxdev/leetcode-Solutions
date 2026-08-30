class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=INT_MIN;
        for(int i=0; i<piles.size(); i++) {
            high=max(high,piles[i]);
        }
        while(low < high) {
            int hours=0;
            int mid=low+(high-low)/2;
            int curr=mid;
            for(int i=0; i<piles.size(); i++) {
                hours+=(piles[i]+mid-1)/mid;
            }
            if(hours > h) { 
                low=mid+1;        
            }
            else {
                high=mid;
            }
        }
        return low;
    }
};