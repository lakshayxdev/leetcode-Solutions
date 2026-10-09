class Solution {
public:
    int valueAfterKSeconds(int n, int k) {
        vector<int> prefix(n,1);
        const int MOD = 1e9 + 7;
        while(k>0) {
            long long sum=0;
            for(int i=0; i<n; i++) {
                sum=(sum+prefix[i])%MOD;
                prefix[i]=sum;
            }
            k--;
        }
        return prefix[n-1];
    }
};