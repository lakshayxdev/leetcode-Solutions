class Solution {
public:
bool isPossible(long long mid, vector<int> &time, int totalTrips) {
    long long count=0;
    for(int i=0; i<time.size(); i++) {
        count+=mid/time[i];
    }
    if(count>=totalTrips) return true;
    return false;
}
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long miniTime = *min_element(time.begin(), time.end());
        long long l = 1;
        long long h = miniTime * totalTrips;
        long long ans=h;
        while(l<=h) {
            long long mid=l+(h-l)/2;
            if(isPossible(mid,time,totalTrips)) {
                ans=mid;
                h=mid-1;
            }
            else {
                l=mid+1;
            }
        }
        return ans;
    }
};