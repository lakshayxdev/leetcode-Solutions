class Solution {
public:
    string reorganizeString(string s) {
        string ans="";
        unordered_map<char,int> freq;
        for(char ch:s) {
            freq[ch]++;
        }
        priority_queue<pair<int,char>> pq;
        for(auto it:freq) {
            pq.push({it.second,it.first});
        }
        pair<int,char> prev={0,'#'};
        while(!pq.empty()) {
            auto temp=pq.top();
            pq.pop();
            if(prev.first > 0) {
                pq.push(prev);
            }
            ans.push_back(temp.second);
            temp.first--;
            prev=temp;
        }
        if(prev.first>0) {
             return "";   
            }
        return ans;
    }
};