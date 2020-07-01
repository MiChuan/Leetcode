class Solution {
public:
    vector<int> printNumbers(int n) {
        vector<int> res;
        int max = pow(10,n);
        for(int i = 1; i < max; ++i){
            res.push_back(i);
        }
        return res;
    }
};