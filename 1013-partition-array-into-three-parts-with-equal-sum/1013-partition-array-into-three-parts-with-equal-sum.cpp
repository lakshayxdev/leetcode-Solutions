class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int sum=0;
        for(int x:arr) {
            sum+=x;
        }
        if(sum%3 != 0) return false;
        int each_sum=sum/3;
        int count=0;
        int running=0;
        int i=0;
        while(i<arr.size()) {
            running+=arr[i];
            if(running==each_sum) {
                count++;
                running=0;
            }
            i++;
        }
        return count>=3;
    }
};