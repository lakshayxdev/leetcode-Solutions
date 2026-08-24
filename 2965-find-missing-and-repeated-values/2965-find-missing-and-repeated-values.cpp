class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int> final_ans;
        vector<int> arr;
        for(auto &row: grid) {
            arr.insert(arr.end(),row.begin(),row.end());
        }
        int size=n*n;
        vector<int> ans(size+1,0);
        for(int i=0; i<arr.size(); i++) {
            ans[arr[i]]++;
        }
         for(int i = 1; i <= size; i++) {
            if(ans[i] == 2) {
                final_ans.push_back(i);
            }
        }
        for(int i = 1; i <= size; i++) {
            if(ans[i] == 0) {
                final_ans.push_back(i);
            }
        }
        return final_ans;
    }
};