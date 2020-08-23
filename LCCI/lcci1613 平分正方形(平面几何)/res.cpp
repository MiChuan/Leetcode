class Solution {
public:
    double isleft(double k, double x, double a, double b){
        return k*(x-a)+b;
    }
    double isup(double k, double y, double a, double b){
        return (y-b)/k+a;
    }
    vector<double> cutSquares(vector<int>& square1, vector<int>& square2) {
        double a = (double)square1[2]/2 + square1[0], b = (double)square1[2]/2 + square1[1];
        double c = (double)square2[2]/2 + square2[0], d = (double)square2[2]/2 + square2[1];
        if(a == c) return {a,(double)min(square1[1],square2[1]),a,(double)max(square1[1]+square1[2],square2[1]+square2[2])};
        vector<double> res(4,0);
        double k = (d-b)/(c-a);
        double left = isleft(k,square1[0],a,b);
        if(left >= square1[1] && left <= square1[1]+square1[2]){
            res[0] = min(square1[0],square2[0]);
            res[1] = isleft(k,res[0],a,b);
            res[2] = max(square1[0]+square1[2],square2[0]+square2[2]);
            res[3] = isleft(k,res[2],a,b);
            return res;
        }
        else{
            if(k > 0){
                res[1] = min(square1[1],square2[1]);
                res[0] = isup(k,res[1],a,b);
                res[3] = max(square1[1]+square1[2],square2[1]+square2[2]);
                res[2] = isup(k,res[3],a,b);
            }
            else{
                res[1] = max(square1[1]+square1[2],square2[1]+square2[2]);
                res[0] = isup(k,res[1],a,b);
                res[3] = min(square1[1],square2[1]);
                res[2] = isup(k,res[3],a,b);
            }
        }
        return res;
    }
};