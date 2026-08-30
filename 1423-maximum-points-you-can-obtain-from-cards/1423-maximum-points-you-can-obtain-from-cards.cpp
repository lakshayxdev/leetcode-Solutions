class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int total=0;
        int curr_sum=0;
        int mini=INT_MAX;
        for(int i=0; i<cardPoints.size(); i++) {
            total+=cardPoints[i];
        }
         if(k == cardPoints.size()) {
            return total;
        }
        int size=cardPoints.size()-k;
        int l=0;
        int r=size-1;
        for(int i=l; i<=r; i++) {
            curr_sum+=cardPoints[i];
        }
        mini=min(mini, curr_sum);
        for(int i=r+1; i<cardPoints.size(); i++) {
            curr_sum+=cardPoints[i];
            curr_sum-=cardPoints[l];
            mini=min(mini, curr_sum);
            l++;
        }
        return total-mini;
    }
};