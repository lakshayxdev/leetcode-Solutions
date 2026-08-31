class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> map;
        vector<int> ans;
        for(int i=0; i<arr.size(); i++) {
            map[arr[i]]++;
        }
        for(auto it:map) {
            ans.push_back(it.second);
        }
        map.clear();
        for(int i=0; i<ans.size(); i++) {
            map[ans[i]]++;
        }
        for(auto it:map) {
            if(it.second>=2) {
                return false;
            }
        }
        return true;
    }
};