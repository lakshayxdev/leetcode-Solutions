class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
        vector<vector<string>> ans;
        for(int i=0; i<responses.size(); i++) {
            unordered_map<string,int> mp;
            vector<string> ans2;
            for(string st:responses[i]) {
                if(mp.find(st)==mp.end()) {
                    mp[st]++;
                }
            }
            for(auto it:mp) {
                ans2.push_back(it.first);
            }
            ans.push_back(ans2);
        }
        unordered_map<string,int> mp;
        for(int i=0; i<ans.size(); i++) {
            for(string st:ans[i]) {
                mp[st]++;
            }
        }
        int maxi=0;
        string str="";
        for(auto it:mp) {
            if(it.second > maxi || 
   (it.second == maxi && it.first < str)) {

    maxi = it.second;
    str = it.first;
}
        }
        return str;
    }
};