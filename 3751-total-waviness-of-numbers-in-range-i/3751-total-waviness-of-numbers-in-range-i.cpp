class Solution {
public:
int solve(const string &num) {
    int n=num.length();
    int count=0;
    if(n<3) return 0;
    for(int i=1; i<n-1; i++) {
        if ((num[i] > num[i + 1] && num[i] > num[i - 1]) || 
                (num[i] < num[i + 1] && num[i] < num[i - 1])) {
                count++;
            }
    }
    return count;
}
    int totalWaviness(int num1, int num2) {
        int count=0;
        for(int i=num1; i<=num2; i++) {
            count+=solve(to_string(i));
        }
        return count;
    }
};