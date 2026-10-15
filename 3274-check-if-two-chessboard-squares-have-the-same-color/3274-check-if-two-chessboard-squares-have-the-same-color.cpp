class Solution {
public:
    bool checkTwoChessboards(string coordinate1, string coordinate2) {
        unordered_map<char,int> mp;
        int i=1;
        for(char ch='a'; ch<='h'; ch++) {
            mp[ch]=i++;
        }
        string color1="";
        string color2="";
        int val1=mp[coordinate1[0]];
        int val2=coordinate1[1];
        if((val1+val2)%2==0) color1+="black";
        else color1+="white";

        int Val1=mp[coordinate2[0]];
        int Val2=coordinate2[1];
        if((Val1+Val2)%2==0) color2+="black";
        else color2+="white";

        if(color1==color2) return true;
        else { return false;
        }
    }
};