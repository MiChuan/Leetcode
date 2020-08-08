class Solution {
public:
    vector<int> drawLine(int length, int w, int x1, int x2, int y) {
        vector<int> p(length,0);
        if (length == 0) return p;
        int row = w / 32;       //一行有多少int
        int start = row * y + x1 / 32;  //线段头所在的int
        int start_s = x1 % 32;          //线段头所在的int的左边需要空出0的个数
        int end = row * y + x2 / 32;    //线段尾所在的int
        int end_s = 31 - x2 % 32;       //线段尾所在的int的右边需要空出0的个数
        for (int i = start; i <= end; i++) {
            p[i] = 0xffffffff;          //置为-1；
        }
        if (start == end) { //对头尾在一个int里时单独处理
            p[start] = (unsigned int)p[start] >> (start_s+ end_s);
            p[end] = (unsigned int)p[end] << end_s;
        }
        else {
            p[start] = (unsigned int)p[start] >> start_s;
            p[end] = (unsigned int)p[end] << end_s;
        }
        return p;
    }
};