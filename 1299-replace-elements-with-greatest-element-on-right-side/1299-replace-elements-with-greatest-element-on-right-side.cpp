class Solution {
public:
int find_maxi(int start, int end, vector<int> &arr, int maxi) {
    if(start==end) {
        return maxi;
    }
    for(int i=start+1; i<end; i++) {
        maxi=max(maxi,arr[i]);
    }
    return maxi;
}
    vector<int> replaceElements(vector<int>& arr) {
        vector<int>ans;
        for(int i=0; i<arr.size(); i++) {
            int val=find_maxi(i,arr.size(),arr,-1);
            ans.push_back(val);
        }
        return ans;
    }
};