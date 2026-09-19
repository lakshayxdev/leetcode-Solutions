class Solution {
public:
    int edgeScore(vector<int>& edges) {
        long long max_sum=INT_MIN;
        long long sum=0;
        vector<long long> score(edges.size(),0);
        for(int i=0; i<edges.size(); i++) {
            score[edges[i]]+=i;
        }
        for(int i=0; i<score.size(); i++) {
            max_sum=max(max_sum,score[i]);
        }
        for(int i=0; i<score.size(); i++) {
            if(score[i]==max_sum) {
                return i;
            }
        }
        return -1;
    }
};