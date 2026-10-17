class Solution {
public:
bool hasFreqK(unordered_map<char,int> &mp, int k) {
    for(auto it:mp) {
        if(it.second>=k) {
            return true;
        }
    }
    return false;
}
    int numberOfSubstrings(string s, int k) {
        int n=s.size();
        if(k==1) return (n*(n+1))/2;
        int count=0;
        for(int i=0; i<n; i++) {
            string sub="";
            unordered_map<char,int> mp;
            for(int j=i; j<n; j++) {
                sub+=s[j];
                mp[s[j]]++;
                if(hasFreqK(mp,k)) count++;
            }
        }
        return count;
    }
};