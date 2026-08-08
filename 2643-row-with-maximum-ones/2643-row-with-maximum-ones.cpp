class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int maxi=INT_MIN;
        int max_row=-1;
        int rows=mat.size();
        int cols=mat[0].size();
        for(int i=0; i<rows; i++) {
            int count=0;
            for(int j=0; j<cols; j++) {
               if(mat[i][j]==1) {
                count++;
               }
            }
            if(count>maxi) {
                maxi=max(maxi,count);
                max_row=i;
            }
        }
        return {max_row,maxi};
    }
};