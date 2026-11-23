class Solution {
public:
bool isPossible(int mid, int days, vector<int> &weights) {
    int sum=0;
    int count=1;
    for(int i=0; i<weights.size(); i++) {
        sum+=weights[i];
        if(sum>mid) {
            count++;
            sum=weights[i];
        }
    }
    if(count<=days) return true;
    return false;
}
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(), weights.end());
        int sum=0;
        for(int x:weights) {
            sum+=x;
        }
        int h=sum;
        int mini=INT_MAX;
        while(l<=h) {
            int mid=l+(h-l)/2;
            if(isPossible(mid,days,weights)) {
                h=mid-1;
                mini=min(mid,mini);
            }
            else {
                l=mid+1;
            }
        }
        if(mini==INT_MAX) return -1;
        return mini;
    }
};