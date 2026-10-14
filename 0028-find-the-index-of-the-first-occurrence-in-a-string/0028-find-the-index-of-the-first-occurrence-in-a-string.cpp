class Solution {
public:
    int strStr(string haystack, string needle) {
        int m=needle.size();
        int n=haystack.size();
        for(int i=0; i<=n-m; ++i) {
            if(haystack.substr(i,m)==needle) return i;
        }
        return -1;
    }
};