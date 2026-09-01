class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int,int>> pq;
        int count=0;
        int n=score.size();
        vector<string> ans(n);
        for(int i=0; i<n; i++) {
            pq.push({score[i],i});
        }
        while(count<3 && !pq.empty()) {
            int index=pq.top().second;
            if(count==0) {
                ans[index]="Gold Medal";
            }
            else if(count==1) {
                ans[index]="Silver Medal";
            }
            else {
                ans[index]="Bronze Medal";
            }
            count++;
            pq.pop();
        }
        int rank=4;
        while(!pq.empty()) {
            int index=pq.top().second;
            ans[index]=to_string(rank);
            pq.pop();
            rank++;
        }
        return ans;
    }
};