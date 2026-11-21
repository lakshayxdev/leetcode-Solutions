class Solution {
public:
    vector<string> assignUmbrella(vector<int>& rain) {
        int alice=0;
        int bob=0;
        vector<string> ans(rain.size());
        for(int i=0; i<rain.size()-1; i++) {
            if(rain[i]==1 && rain[i+1]==1) {
                if(alice<bob || alice==bob) { 
                    ans[i]="Alice";
                    alice++;
                }
                else  {
                    ans[i]="Bob";
                    bob++;
                }
            }
            else if(rain[i]==0) ans[i]="None";
            else if(rain[i]==1 && rain[i+1]==0) {
                ans[i]="Bob";
                bob++;
            }
        }
        int n=rain.size();
        if(rain[n-1]==1) {
            ans[n-1]="Bob";
            bob++;
        }
        else {
            ans[n-1]="None";
        }
        return ans;
    }
};