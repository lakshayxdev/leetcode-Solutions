class Solution {
public:
struct Compare {
    bool operator()(const pair<int,string>& a,
                    const pair<int,string>& b) {

        if(a.first != b.first)
            return a.first > b.first;

        return a.second < b.second;
    }
};
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        for(int i=0; i<words.size(); i++) {
            mp[words[i]]++;
        }
        priority_queue<
        pair<int,string>,
        vector<pair<int,string>>,
        Compare
        > pq;
        vector<string> ans;
        for(auto it:mp) {
            pq.push({it.second,it.first});
            if(pq.size()>k) {
                pq.pop();
            }
        }
        while(!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        sort(ans.begin(),ans.end(),[&](string &a, string &b) {
            if(mp[a] != mp[b]) {
                return mp[a]>mp[b];
            }
            return a<b;
        });
        return ans;
    }
};