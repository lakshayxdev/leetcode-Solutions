class Solution {
public:
int countDigit(int num) {
    if(num<0) {
        num=abs(num);
    }
    if(num==0) return 1;
    int temp=num;
    int digit=0;
    while(temp!=0) {
        digit++;
        temp/=10;
    }
    return digit;
}
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int> ans2;
        for(int i=0; i<n; i++) {
            int maxi=0;
            for(int j=0; j<m; j++) {
                int num=grid[j][i];
                int ans=countDigit(num);
                if(num<0) ans++;
                maxi=max(maxi,ans);
            }
            ans2.push_back(maxi);
        }
        return ans2;
    }
};