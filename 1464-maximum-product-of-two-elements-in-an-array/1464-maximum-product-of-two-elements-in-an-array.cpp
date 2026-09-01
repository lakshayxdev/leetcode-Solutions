class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int> pq;
        for(int x:nums) {
            pq.push(x);
        }
            int first=pq.top();
            pq.pop();
            int second=pq.top();
        return (first-1)*(second-1);
    }
};