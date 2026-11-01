class Solution {
public:
void findValue(string s, string chars, vector<int>& vals, vector<int>& ans) {
    unordered_map<char, pair<bool, int>> mp;

    for (int i = 0; i < chars.size(); i++) {
        mp[chars[i]] = {true, i};
    }

    unordered_map<char, int> mp2;
    int idx = 1;

    for (char ch = 'a'; ch <= 'z'; ch++) {
        mp2[ch] = idx++;
    }

    for (int i = 0; i < s.size(); i++) {
        auto it = mp.find(s[i]);

        if (it != mp.end()) {
            ans.push_back(vals[it->second.second]);
        } else {
            ans.push_back(mp2[s[i]]);
        }
    }
}
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        vector<int> ans;
        findValue(s,chars,vals,ans);
        int sum=0;
        int maxsum=0;
        for(int i=0; i<ans.size(); i++) {
            sum+=ans[i];
            maxsum=max(sum,maxsum);
            if(sum<0) {
                sum=0;
            }
        }
        return maxsum;
    }
};