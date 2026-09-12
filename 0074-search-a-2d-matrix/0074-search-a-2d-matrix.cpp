class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        int start=0;
        int end=rows*cols-1;
        while(start <= end) {
            int mid=start+(end-start)/2;
            int new_row=mid/cols;
            int new_col=mid%cols;
            if(target==matrix[new_row][new_col]) {
                return true;
            }
            else if(target < matrix[new_row][new_col]) {
                end=mid-1;
            }
            else {
                start=mid+1;
            }
        }
        return false;
    }
};