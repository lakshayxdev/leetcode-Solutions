class Solution {
public:
    string reverseWords(string s) {
        vector<string> v;
        string str="";
        for(int i=0; i<s.size(); i++) {
            if(s[i]!=' ') {
               str.push_back(s[i]); 
            }
            else {
                if(str!="") {
                    v.push_back(str);
                    str="";
                }
            }
        }

        if(str != "") {
        v.push_back(str);
        }

        int i=0;
        int j=v.size()-1;
        while(i<j) {
            swap(v[i],v[j]);
            i++;
            j--;
        }
        string ans="";
        for(int i=0; i<v.size(); i++) {
            ans+=v[i];
            if(i!=v.size()-1) {
                ans+=' ';
            }
        }
        return ans;
    }
};