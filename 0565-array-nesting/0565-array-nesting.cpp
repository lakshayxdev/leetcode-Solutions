class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n=nums.size();
        int maxi=INT_MIN;
        unordered_map<int,bool> visited;
        for(int i=0; i<n; i++) {
             if(visited[nums[i]]) {
                continue;
             }
             int count=0;
             int curr=i;
             while(!visited[nums[curr]]) {
                visited[nums[curr]]=true;
                curr=nums[curr];
                count++;
             }
             maxi=max(maxi,count);
        }
        return maxi;
    }
};