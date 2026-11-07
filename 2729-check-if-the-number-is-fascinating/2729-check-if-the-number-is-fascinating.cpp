class Solution {
public:
    bool isFascinating(int n) {
        vector<bool> check(10,false);
        string final=to_string(n*2)+to_string(n*3)+to_string(n);
        if(final.length()!=9) return false;
        for(char ch:final) {
            check[ch-'0']=true;
        }
        if(check[0]==true) return false;
        for(int i=1; i<check.size(); i++) {
            if(check[i]==false) return false;
        }
        return true;
    }
};