class Solution {
public:
    int minChanges(string s) {
        int ones=0;
        int zeroes=0;
        int l=0;
        int ans=0;
        for(int i=0; i<s.size(); i++) {
            if(s[i]=='0') zeroes++;
            else ones++;

            if(i%2==1) {
                ans+=min(zeroes,ones);
                ones=0;
                zeroes=0;
            }
        }
        return ans;
    }
};