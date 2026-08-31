class Solution {
public:
bool search(vector<int> &arr, int target) {
    for(int i=0; i<arr.size(); i++) {
        if(arr[i]==target) {
            return true;
        }
    }
    return false;
}
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> final_ans;
        vector<int> ans;
          unordered_set<int> visited;
        for(int i=0; i<nums1.size(); i++) {
            int element=nums1[i];
             if(visited.count(element))
                continue;

            visited.insert(element);
            bool found=search(nums2, element);
            if(!found) {
                ans.push_back(element);
            }
        }
        final_ans.push_back(ans);
        ans.clear();
        visited.clear();
        for(int i=0; i<nums2.size(); i++) {
            int element=nums2[i];
             if(visited.count(element))
                continue;

            visited.insert(element);
            bool found=search(nums1, element);
            if(!found) {
                ans.push_back(element);
            }
        }
        final_ans.push_back(ans);
        return final_ans;
    }
};