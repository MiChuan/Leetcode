class Solution {
public:
    vector<int> drawLine(int length, int w, int x1, int x2, int y) {
        vector<int> pixel(length, 0);
        int rowIntNum = w / 32;//一行有多少int
        
        int begin = rowIntNum * y + x1 / 32;//线段头所在的int
        int end = rowIntNum * y + x2 / 32;//线段尾所在的int

        for (int i = begin; i <= end; i++) pixel[i] = -1;//0xffffffff
        
        pixel[begin] = pixel[begin] & unsigned(-1) >> (x1 % 32);
        pixel[end] = pixel[end] & unsigned(-1) << (32 - x2 % 32 - 1);

        return pixel;
    }
};