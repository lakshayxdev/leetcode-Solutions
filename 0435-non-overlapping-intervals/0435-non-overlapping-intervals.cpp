class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int count=0;
        sort(intervals.begin(),intervals.end());
        int prev=0;
        for(int i=1; i<intervals.size(); i++) {
            if(intervals[i][0] < intervals[prev][1]) {
                count++;
                if(intervals[i][1] < intervals[prev][1]) {
                    prev=i;
                }
            }
            else {
                prev=i;
            }
        }
        return count;
    }
};