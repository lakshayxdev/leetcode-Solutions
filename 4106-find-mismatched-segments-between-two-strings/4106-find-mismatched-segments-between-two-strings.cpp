class Solution {
public:
    vector<vector<string>> findMismatchedSegments(string s1, string s2) {
        vector<vector<string>> ans;
        int n=s1.size();
        int m=s2.size();
        int i=0;
        int j=0;
        string sub1="";
        string sub2="";
        vector<string> dummy;
        while(i<n && j<m) {
            if(s1[i]==s2[i]) {
                if(!sub1.empty() && !sub2.empty()) {
                    dummy.push_back(sub1);
                    dummy.push_back(sub2);
                    ans.push_back(dummy);
                }
                dummy.clear();
                sub1="";
                sub2="";
                i++;
                j++;
            }
            else {
                sub1+=s1[i];
                sub2+=s2[j];
                i++;
                j++;
            }
        }
        if(!sub1.empty() && !sub2.empty()) {
            dummy.push_back(sub1);
            dummy.push_back(sub2);
            ans.push_back(dummy);
        }
        return ans;
    }
};