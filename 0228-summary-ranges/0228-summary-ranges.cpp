class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        string str="";
        int start=0;
        while(start < nums.size()) {
            if(start==nums.size()-1) {
                str+=to_string(nums[start]);
                ans.push_back(str);
                break;
            }
            str+=to_string(nums[start]);
            int j=start;
            while ( j+1 <nums.size() && nums[j+1]==nums[j]+1) {
                j++;
            }
            if(start==j) {
                ans.push_back(str);
            }
            else {
                str+="->";
                str+=to_string(nums[j]);
                ans.push_back(str);
            }
                start=j+1;
                str.clear();
        }
        return ans;
    }
};