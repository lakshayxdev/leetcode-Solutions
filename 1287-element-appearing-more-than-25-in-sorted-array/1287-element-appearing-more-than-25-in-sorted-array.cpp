class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        if(arr.size()==1) {
            return arr[0];
        }
        int count=arr.size()/4;
        int initial=1;
        for(int i=0; i<arr.size()-1; i++) {
            if(arr[i]==arr[i+1]) {
                initial++;
                if(initial>count) {
                    return arr[i];
                }
            }
            else {
                initial=1;
            }
        }
        return -1;
    }
};