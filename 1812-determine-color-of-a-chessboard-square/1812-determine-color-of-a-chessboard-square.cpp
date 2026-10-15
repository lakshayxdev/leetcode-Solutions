class Solution {
public:
    bool squareIsWhite(string coordinates) {
        unordered_map<char,int> mp;
        int i=1;
        for(char ch='a'; ch<='h'; ch++) {
            mp[ch]=i++;
        }
        int val1=mp[coordinates[0]];
        int val2=coordinates[1];
        if((val1+val2)%2==0) return false;
        else return true;
    }
};