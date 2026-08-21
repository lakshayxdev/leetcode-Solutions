class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> group;
        for(int i=0; i<strs.size(); i++) {
            string element=strs[i];
            sort(element.begin(),element.end());
            group[element].push_back(strs[i]);
            
        }
         vector<vector<string>> result;

for (auto& [key, lst] : group) {
    result.push_back(lst);
}
return result;
    }
};