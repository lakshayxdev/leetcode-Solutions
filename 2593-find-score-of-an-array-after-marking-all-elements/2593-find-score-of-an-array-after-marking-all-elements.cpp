class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long score=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i=0; i<nums.size(); i++) {
            pq.push({nums[i],i});
        }
        vector<bool> marked(nums.size(),false);
        while(!pq.empty()) {
            auto it=pq.top();
            pq.pop();
            int val=it.first;
            int index=it.second;
            if(marked[index]) continue;
            marked[index]=true;
            if (index > 0) marked[index - 1] = true;
            if (index + 1 < nums.size()) marked[index + 1] = true;
            score+=val;
        }
        return score;
    }
};