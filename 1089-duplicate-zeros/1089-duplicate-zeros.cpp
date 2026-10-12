class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n=arr.size();
        vector<int> ans;
        for(int i=0; i<n; i++) {
            ans.push_back(arr[i]);
            if(arr[i]==0) {
                ans.push_back(0);
            }
            if(ans.size()>=n) break;
        }
        arr=vector<int>(ans.begin(),ans.begin()+n);
    }
};