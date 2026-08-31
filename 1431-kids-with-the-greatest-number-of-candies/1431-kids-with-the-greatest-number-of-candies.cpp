class Solution {
public:
int find_maxi(vector<int> &arr) {
    int maxi=INT_MIN;
    for(int i=0; i<arr.size(); i++) {
        maxi=max(maxi,arr[i]);
    }
    return maxi;
}
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> ans;
       for(int i=0; i<candies.size(); i++) {
        vector<int> temp=candies;
        temp[i]+=extraCandies;
        int largest=find_maxi(temp);
        if(largest==temp[i]) {
            ans.push_back(true);
        }
        else {
            ans.push_back(false);
        }
       }
       return ans;
    }
};