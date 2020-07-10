class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        vector<int> res;
        if(a.size() != 0){
            res.resize(a.size());
            res[0] = 1;
            int tmp = 1;
            for(int i = 1; i < a.size(); ++i){
                res[i] = res[i-1] * a[i-1];
            }
            for(int i = a.size() - 2; i >= 0; i--) {
                tmp *= a[i + 1];
                res[i] *= tmp;
            }
        }
        return res;
    }
};