class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count=0;
        for(int i=0; i<details.size(); i++) {
            string str=details[i];
            int first=str[11]-'0';
            int second=str[12]-'0';
            if(first*10+second>60) count++;
        }
        return count;
    }
};