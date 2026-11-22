class Solution {
public:
    bool checkString(string s) {
        int index=-1;
        for(int i=0; i<s.size(); i++) {
            if(s[i]=='b') {
                index=i;
                break;
            }
        }
        for(int i=index; i<s.size(); i++) {
            if(s[i]=='a') return false;
        }
        return true;
    }
};