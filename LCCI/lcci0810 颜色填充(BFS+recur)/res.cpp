class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor)
    {
        if (newColor == image[sr][sc]) return image; //这个条件是防止无限递归
        int old = image[sr][sc];
        image[sr][sc] = newColor;
        digui(image, sr - 1, sc, newColor, old);
        digui(image, sr + 1, sc, newColor, old);
        digui(image, sr, sc - 1, newColor, old);
        digui(image, sr, sc + 1, newColor, old);
        return image;
    }
    void digui(vector<vector<int>>& image, int sr, int sc, int &newColor, int &old)
    {
        if (sr >= 0 && sc >= 0 && sr < image.size() && sc < image[0].size() && image[sr][sc] == old)
        {
                image[sr][sc] = newColor;
                digui(image, sr - 1, sc, newColor, old);
                digui(image, sr + 1, sc, newColor, old);
                digui(image, sr, sc - 1, newColor, old);
                digui(image, sr, sc + 1, newColor, old);
        }
    }
};