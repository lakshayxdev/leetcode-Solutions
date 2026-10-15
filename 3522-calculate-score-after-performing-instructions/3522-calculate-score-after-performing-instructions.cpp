class Solution {
public:
    long long calculateScore(vector<string>& instructions, vector<int>& values) {
        unordered_map<int,bool> mp;
        long long score=0;
        int i=0;
        while(i<instructions.size()) {
            if(mp[i]==true) {
                break;
            }
            else if(instructions[i]=="add") {
                mp[i]=true;
                score+=values[i];
                i++;
            }
            else {
                mp[i]=true;
                int index=i+values[i];
                i=index;
            }
        }
        return score;
    }
};