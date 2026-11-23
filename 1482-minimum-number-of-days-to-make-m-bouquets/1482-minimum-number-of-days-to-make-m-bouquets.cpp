class Solution {
public:
bool isValid(int x, int m, int k, vector<int> &bloomDay) {
    vector<int> temp=bloomDay;
    for(int i=0; i<temp.size(); i++) {
        if(temp[i]<=x) {
            temp[i]=1;
        }
        else {
            temp[i]=0;
        }
    }
    int ans=0;
    int count=0;
    for(int i=0; i<temp.size(); i++) {
        if(temp[i]==1) {
            ans++;
            if(ans==k) {
                count++;
                ans=0;
            }
        }
        else {
            ans=0;
        }
    }
    if(count>=m) return true;
    return false;
}
    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long long)m*k > bloomDay.size()) {
            return -1;
        }
        int mini=INT_MAX;
        int maxi=INT_MIN;
        for(int num:bloomDay) {
            maxi=max(num,maxi);
            mini=min(num,mini);
        }
        int l=mini;
        int h=maxi;
        int mini2=INT_MAX;
        while(l<=h) {
            int mid=l+(h-l)/2;
            if(isValid(mid,m,k,bloomDay)) {
                mini2=min(mini2,mid);
                h=mid-1;
            }
            else {
                l=mid+1;
            }
        }
        if(mini2==INT_MAX) return -1;
        return mini2;
    }
};