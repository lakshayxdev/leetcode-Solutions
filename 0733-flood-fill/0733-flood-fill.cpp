class Solution {
public:
void change_color(vector<vector<int>>& image, int sr,int sc,int color,int original) {
    int rows=image.size();
    int cols=image[0].size();
    if(sr<0 || sr>=rows) {
        return;
    }
    if(sc<0 || sc>=cols) {
        return;
    }
    if(image[sr][sc]!=original) {
        return;
    }
    if(image[sr][sc]==original) {
        image[sr][sc]=color;
        change_color(image,sr-1,sc,color,original);
        change_color(image,sr+1,sc,color,original);
        change_color(image,sr,sc-1, color,original);
        change_color(image,sr,sc+1,color,original);
    }

}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int rows=image.size();
        int cols=image[0].size();
        int original=image[sr][sc];
        if(original == color) {
            return image;
        }
        else {
             change_color(image,sr,sc,color,original);
        }
        return image;
    }
};