class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int l=0;
        int ans=INT_MAX;
        int white=0;
        for(int r=0; r<k; r++) {
            if(blocks[r]=='W') white++;
        }
        ans=min(ans,white);
        for(int i=k; i<blocks.size(); i++) {
            if(blocks[i]=='W') {
                white++;
            } 
            if(blocks[l]=='W') {
                white--;
            }
            l++;
            ans=min(ans,white);
        }
        return ans;
    }
};